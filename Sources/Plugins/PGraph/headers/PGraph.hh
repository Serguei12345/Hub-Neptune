//
// PGraph.hh for PGraph in /home/ovoyan_s/Hub-Neptune/Sources/Plugins/PGraph
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 20:32:37 2015 ovoyan_s
// Last update Tue Feb 10 12:28:24 2015 ovoyan_s
//

#ifndef			PGRAPH_HH_
# define		PGRAPH_HH_

# include		"APlugin.hh"

class			PGraph : public APlugin
{
public:
  PGraph();
  ~PGraph();

  void			initialisation();
  std::string		update();
  std::string		doRequest(const std::string& request);
};

#endif			/*	PGRAPH_HH_	*/
