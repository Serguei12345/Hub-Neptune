//
// PGraph.hh for PGraph in /home/ovoyan_s/Hub-Neptune/Sources/Plugins/PGraph
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 20:32:37 2015 ovoyan_s
// Last update Thu Mar  5 20:05:45 2015 ovoyan_s
//

#ifndef			PGRAPH_HH_
# define		PGRAPH_HH_

# include		<GL/gl.h>
# include		<GL/glu.h>
# include		<iostream>
# include		<map>
# include		<SDL/SDL.h>

# include		"APlugin.hh"
# include		"EventActions.hh"
# include		"FileManager.hh"
# include		"Random.hh"

class			PGraph : public APlugin
{
private:
  std::map<std::string, std::vector<std::string> > configMap;
  EventActions		eventActions;

public:
  PGraph();
  ~PGraph();

  void				initialisation(const std::string& configFile);
  std::vector<std::string>	update();
  std::vector<std::string>	doRequest(const std::string& request);
};

#endif			/*	PGRAPH_HH_	*/
