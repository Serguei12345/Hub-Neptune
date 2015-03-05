//
// Ecosysteme.cpp for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Sources/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 20:01:40 2015 ovoyan_s
// Last update Thu Mar  5 20:29:10 2015 ovoyan_s
//

#include		"Ecosysteme.hh"

Ecosysteme::Ecosysteme()
{
  
}

Ecosysteme::~Ecosysteme()
{

}

/*
**	Load plugins in the Plugins directory in root directory
*/

void			Ecosysteme::loadPlugin(const std::string& nameOfPlugin,
					       const std::vector<std::string>& pluginFilePath)
{
  PluginManager		*pm = new PluginManager();
  
  pm->loadPlugin(pluginFilePath[0]);
  pm->setNameOfPlugin(nameOfPlugin);
  pm->setConfigFile(pluginFilePath[1]);
  this->pluginManagers.push_back(pm);
}

/*
**	Calls all the initialisations of the plugin constructors
*/

void			Ecosysteme::initialisation()
{
  unsigned int		listSize = this->pluginManagers.size();

  for (unsigned int counter = 0; counter < listSize; ++counter)
    this->pluginManagers[counter]->getPlugin()->initialisation(this->pluginManagers[counter]->getConfigFile());
}

/*
**	Execute requests in the end of each loop
*/

void			Ecosysteme::executeRequests()
{
  this->requestManager.requestsMaker(this->pluginManagers);
  this->requestManager.clearList();
}

void			Ecosysteme::start()
{
  bool			isGood = true;
  unsigned int		listSize = this->pluginManagers.size();

  while (isGood == true)
    {
      for (unsigned int counter = 0; counter < listSize; ++counter)
	{
	  std::vector<std::string> requests = this->pluginManagers[counter]->getPlugin()->update();
	  if (requests.size() != 0)
	    this->requestManager.addRequestList(requests);
	}
      this->executeRequests();
    }
}

/*
**	Loads plugins and integrates them as modules
*/

void			Ecosysteme::loadPlugins(const std::string& pluginFilePath)
{
  FileManager		fileManager;
  fileManager.loadFile(pluginFilePath);
  std::map<std::string, std::vector<std::string> >
    contentOfMainFile = fileManager.getConfigContent();
  
  std::map<std::string, std::vector<std::string> >::iterator itEnd = contentOfMainFile.end();
  for (std::map<std::string, std::vector<std::string> >::iterator it = contentOfMainFile.begin();
       it != itEnd; ++it)
    this->loadPlugin((*it).first, (*it).second);

  this->initialisation();
  this->start();
}

/*
**	Load scripts
*/

void			Ecosysteme::loadScripts(const std::string& scriptFilePath)
{
  (void)scriptFilePath;
}

void			Ecosysteme::initialisation(char **strConfigs)
{
  std::string		configFileName = strConfigs[1];
  FileManager		fileManager;
  fileManager.loadFile(configFileName);
  std::map<std::string, std::vector<std::string> >
    contentOfMainFile = fileManager.getConfigContent();

  if (contentOfMainFile["PluginFile"].size() == 0
      || contentOfMainFile["ScriptFile"].size() == 0)
    throw (MyException ("The general configuration files are corrupted"));
  this->loadPlugins(contentOfMainFile["PluginFile"][0]);
  this->loadScripts(contentOfMainFile["ScriptFile"][0]);
}

/*
**	The first method to call (starts the program)
*/

void			Ecosysteme::initEcosystem(char **strConfigs)
{
  this->initialisation(strConfigs);
}
