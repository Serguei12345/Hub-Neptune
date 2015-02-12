//
// PluginManager.hh for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Sources/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 20:05:12 2015 ovoyan_s
// Last update Tue Feb 10 13:20:08 2015 ovoyan_s
//

#ifndef		PLUGIN_MANAGER_HH_
# define	PLUGIN_MANAGER_HH_

# include	<dlfcn.h>

# include	"APlugin.hh"
# include	"FileManager.hh"

class		PluginManager
{
private:
  APlugin	*aPlugin;
  void		*handle;
  std::string	nameOfPlugin;

public:
  PluginManager();
  ~PluginManager();

  void		loadPlugin(const std::string& filePath);

  void		setNameOfPlugin(const std::string& nameOfPluginToSet);

  std::string	&getNameOfPlugin() const;
  APlugin	*getPlugin();
};

#endif		/*	PLUGIN_MANAGER_HH_	*/
