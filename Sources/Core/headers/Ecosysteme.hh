//
// Ecosysteme.hh for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Sources/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 19:59:12 2015 ovoyan_s
// Last update Thu Feb 12 18:55:49 2015 ovoyan_s
//

#ifndef			ECOSYSTEME_HH_
# define		ECOSYSTEME_HH_

# include		<iostream>
# include		<vector>

# include		"FileManager.hh"
# include		"PluginManager.hh"

class			Ecosysteme
{
private:
  std::vector<PluginManager*>	pluginManagers;

public:
  Ecosysteme();
  ~Ecosysteme();

  void			initialisation();
  void			start();

  void			loadPlugin(const std::string& nameOfPlugin,
				   const std::string& pluginFilePath);
  void			loadPlugins(const std::string& pluginFilePath);
  void			loadScripts(const std::string& scriptFilePath);
  void			initialisation(char **strConfigs);
  void			start(char **strConfigs);
};

#endif			/*	ECOSYSTEME_HH_	*/
