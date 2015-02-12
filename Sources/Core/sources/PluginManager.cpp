//
// PluginManager.cpp for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Sources/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 20:04:41 2015 ovoyan_s
// Last update Tue Feb 10 13:31:27 2015 ovoyan_s
//

#include		"PluginManager.hh"

PluginManager::PluginManager()
{

}

PluginManager::~PluginManager()
{
  if (this->handle != NULL)
    dlclose(this->handle);
}

void			PluginManager::loadPlugin(const std::string& filePath)
{
  FileManager		fm;
  APlugin*		(*pluginRet)();

  fm.loadFile(filePath);
  std::string		nfm = fm.getNameOfFile();
  this->handle = dlopen((char*)filePath.c_str(), RTLD_LAZY);
  if (this->handle == NULL)
    throw (MyException("DL handle failed"));
  pluginRet = (APlugin*(*)())dlsym(handle, "retPlugin");
 
  this->aPlugin = pluginRet();
  this->aPlugin->initialisation();
  if (this->aPlugin == NULL)
    {
      if (this->handle != NULL)
	dlclose(this->handle);
      throw (MyException ("Plugin not loaded"));
    }
}

void			PluginManager::setNameOfPlugin(const std::string& nameOfPluginToSet)
{
  this->nameOfPlugin = nameOfPluginToSet;
}

std::string		&PluginManager::getNameOfPlugin() const
{
  return (const_cast<std::string&>(this->nameOfPlugin));
}

APlugin			*PluginManager::getPlugin()
{
  return (this->aPlugin);
}
