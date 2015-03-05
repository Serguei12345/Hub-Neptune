//
// PluginManager.cpp for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Sources/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 20:04:41 2015 ovoyan_s
// Last update Thu Feb 12 21:07:53 2015 ovoyan_s
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
  APlugin*		(*pluginRet)();

  errno = 0;
  this->handle = dlopen((char*)filePath.c_str(), RTLD_NOW);

  if (this->handle == NULL)
    {
      throw (MyException(dlerror()));
    }
  pluginRet = (APlugin*(*)())dlsym(handle, "retPlugin");
 
  this->aPlugin = pluginRet();
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

void			PluginManager::setConfigFile(const std::string& configFileOfPluginToSet)
{
  this->configFileOfPlugin = configFileOfPluginToSet;
}

std::string		&PluginManager::getNameOfPlugin() const
{
  return (const_cast<std::string&>(this->nameOfPlugin));
}

APlugin			*PluginManager::getPlugin()
{
  return (this->aPlugin);
}

std::string		&PluginManager::getConfigFile() const
{
  return (const_cast<std::string&>(this->configFileOfPlugin));
}
