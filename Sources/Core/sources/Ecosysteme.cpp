//
// Ecosysteme.cpp for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Sources/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 20:01:40 2015 ovoyan_s
// Last update Thu Feb 12 19:05:13 2015 ovoyan_s
//

#include		"Ecosysteme.hh"

Ecosysteme::Ecosysteme()
{
  
}

Ecosysteme::~Ecosysteme()
{

}

void			Ecosysteme::loadPlugin(const std::string& nameOfPlugin,
					       const std::string& pluginFilePath)
{
  try
    {
      PluginManager		*pm = new PluginManager();
      
      pm->loadPlugin(pluginFilePath);
      pm->setNameOfPlugin(nameOfPlugin);
      this->pluginManagers.push_back(pm);
    }
  catch (std::exception e)
    {
      std::cout << e.what() << std::endl;
    }
}

void			Ecosysteme::initialisation()
{
  unsigned int		listSize = this->pluginManagers.size();

  for (unsigned int counter = 0; counter < listSize; ++counter)
    this->pluginManagers[counter]->getPlugin()->initialisation();
}

void			Ecosysteme::start()
{
  bool			isGood = true;
  unsigned int		listSize = this->pluginManagers.size();

  while (isGood == true)
    for (unsigned int counter = 0; counter < listSize; ++counter)
      this->pluginManagers[counter]->getPlugin()->update();
}

void			Ecosysteme::loadPlugins(const std::string& pluginFilePath)
{
  FileManager		fileManager;
  fileManager.loadFile(pluginFilePath);
  std::map<std::string, std::string>	contentOfMainFile = fileManager.getConfigContent();
  
  std::map<std::string, std::string>::iterator itEnd = contentOfMainFile.end();

  for (std::map<std::string, std::string>::iterator it = contentOfMainFile.begin();
       it != itEnd; ++it)
      this->loadPlugin((*it).first, (*it).second);

  this->initialisation();
  this->start();
}

void			Ecosysteme::loadScripts(const std::string& scriptFilePath)
{
  (void)scriptFilePath;
}

void			Ecosysteme::initialisation(char **strConfigs)
{
  std::string		configFileName = strConfigs[1];
  FileManager		fileManager;
  fileManager.loadFile(configFileName);
  std::map<std::string, std::string>	contentOfMainFile = fileManager.getConfigContent();
  
  this->loadPlugins(contentOfMainFile["PluginFile"]);
  this->loadScripts(contentOfMainFile["ScriptFile"]);
}

void			Ecosysteme::start(char **strConfigs)
{
  this->initialisation(strConfigs);
}