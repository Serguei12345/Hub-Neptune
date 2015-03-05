//
// PGraph.hh for PGraph in /home/ovoyan_s/Hub-Neptune/Sources/Plugins/PGraph
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 20:32:37 2015 ovoyan_s
// Last update Thu Mar  5 17:05:37 2015 ovoyan_s
//

#ifndef			PGRAPH_HH_
# define		PGRAPH_HH_

# include		<vector>

# include		"APlugin.hh"

class			PGraph : public APlugin
{
public:
  PGraph();
  ~PGraph();

  void				initialisation();
  std::vector<std::string>	update();
  std::vector<std::string>	doRequest(const std::string& request);
};

#endif			/*	PGRAPH_HH_	*/
