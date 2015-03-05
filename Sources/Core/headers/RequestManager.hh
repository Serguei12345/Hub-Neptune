//
// RequestManager.hh for Neptune in /home/ovoyan_s/Hub-Neptune/Sources/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon Mar  2 18:32:54 2015 ovoyan_s
// Last update Thu Mar  5 18:54:49 2015 ovoyan_s
//

#ifndef		REQUEST_MANAGER_HH_
# define	REQUEST_MANAGER_HH_

# include	<vector>

# include	"Containers.hpp"
# include	"PluginManager.hh"
# include	"Request.hh"

class		RequestManager
{
private:
  std::vector<Request>	requestsList;

public:
  RequestManager();
  ~RequestManager();

  void		addRequestList(const std::vector<std::string> &requestsListToAdd);
  Request	&getRequestAt(const int it) const;
  void		clearList();
  void		deleteRequestAt(const int it);
  PluginManager*	getPluginManagerAt(std::vector<PluginManager*> &pluginsManagers,
					   const std::string &nameOfPlugin);
  void		requestsMaker(std::vector<PluginManager*> &pluginsManagers);
  std::vector<std::string>	requestForPlugin(const Request &request, std::vector<PluginManager*> &pluginsManagers);
};

#endif		/*	REQUEST_MANAGER_HH_	*/
