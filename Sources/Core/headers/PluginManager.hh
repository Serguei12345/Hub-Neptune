//
// PluginManager.hh for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Sources/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 20:05:12 2015 ovoyan_s
// Last update Thu Feb 12 21:01:17 2015 ovoyan_s
//

#ifndef		PLUGIN_MANAGER_HH_
# define	PLUGIN_MANAGER_HH_

# include	<dlfcn.h>
# include	<errno.h>

# include	"APlugin.hh"
# include	"FileManager.hh"

class		PluginManager
{
private:
  APlugin	*aPlugin;
  void		*handle;
  std::string	nameOfPlugin;
  std::string	configFileOfPlugin;

public:
  PluginManager();
  ~PluginManager();

  void		loadPlugin(const std::string& filePath);

  void		setNameOfPlugin(const std::string& nameOfPluginToSet);
  void		setConfigFile(const std::string& configFileOfPluginToSet);

  std::string	&getNameOfPlugin() const;
  APlugin	*getPlugin();
  std::string	&getConfigFile() const;
};

#endif		/*	PLUGIN_MANAGER_HH_	*/
