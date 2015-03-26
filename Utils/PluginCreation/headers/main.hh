//
// main.hh for PluginCreation in /home/ovoyan_s/Hub-Neptune/Utils/PluginCreation
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Thu Mar 19 14:37:18 2015 ovoyan_s
// Last update Fri Mar 20 16:21:26 2015 ovoyan_s
//

#ifndef			MAIN_HH_
# define		MAIN_HH_

# include		<iostream>
# include		<sys/stat.h>
# include		<sys/types.h>
# include		<unistd.h>

# include		"File.hh"
# include		"Containers.hpp"

std::string		vecToString(const std::vector<std::string>& vecToTransform);
void			creationOfHeaderFiles(const std::string& pluginName,
					      const std::string& className);
void			creationOfSourceFiles(const std::string& pluginName,
					      const std::string& className);
void			creationOfRepertories(const std::string& pluginName);
void			creationOfMakefile(const std::string& pluginName,
					   const std::string& className);
int			main();

#endif			/*	MAIN_HH_	*/
