//		PluginName : ClassName

#ifndef			PLUGIN_NAME_HH_
# define		PLUGIN_NAME_HH_

# include		<GL/gl.h>
# include		<GL/glu.h>
# include		<iostream>
# include		<map>
# include		<SDL/SDL.h>

# include		"APlugin.hh"

class			ClassName : public APlugin
{
public:
  ClassName();
  ~ClassName();

  void				initialisation(const std::string& configFile);
  std::vector<std::string>	update();
  std::vector<std::string>	doRequest(const std::string& request);
};

#endif			/*	PGRAPH_HH_	*/
