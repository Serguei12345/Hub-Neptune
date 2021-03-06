//
// RequestManager.cpp for Neptune in /home/ovoyan_s/Hub-Neptune/Sources/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon Mar  2 18:46:16 2015 ovoyan_s
// Last update Thu Mar  5 20:46:17 2015 ovoyan_s
//

#include	"RequestManager.hh"

RequestManager::RequestManager()
{

}

RequestManager::~RequestManager()
{

}

void		RequestManager::addRequestList(const std::vector<std::string> &requestsListToAdd)
{
  unsigned int	sizeOfListToAdd = requestsListToAdd.size();

  for (unsigned int counter = 0; counter < sizeOfListToAdd; ++counter)
    {
      Request request(requestsListToAdd[counter]);
      this->requestsList.push_back(request);
    }
}

Request		&RequestManager::getRequestAt(const int it) const
{
  return (const_cast<Request&>(this->requestsList[it]));
}

void		RequestManager::clearList()
{
  this->requestsList.clear();
}

void		RequestManager::deleteRequestAt(const int it)
{
  this->requestsList.erase(this->requestsList.begin() + it);
}

PluginManager	*RequestManager::getPluginManagerAt(std::vector<PluginManager*> &pluginsManagers,
						    const std::string &nameOfPlugin)
{
  unsigned int listSize = pluginsManagers.size();

  for (unsigned int counter = 0; counter < listSize; ++counter)
    if (pluginsManagers[counter]->getNameOfPlugin() == nameOfPlugin)
      return (pluginsManagers[counter]);
  return (NULL);
}

std::vector<std::string>	RequestManager::requestForPlugin(const Request &request,
								 std::vector<PluginManager*>
								 &pluginsManagers)
{
  MyString	messageOfRequest = request.getRequest();
  std::string	nameOfPlugin = messageOfRequest.GetSectionOfString('\t', 0, 1);
  std::string	requestAsk = messageOfRequest.GetSectionOfString('\t', 1, 2);

  if (nameOfPlugin == "QUIT")
    throw (MyException ("Quit"));
  return (this->getPluginManagerAt(pluginsManagers, nameOfPlugin)->getPlugin()->doRequest(requestAsk));
}

void		RequestManager::requestsMaker(std::vector<PluginManager*> &pluginsManagers)
{
  unsigned int listSize = this->requestsList.size();
  std::vector<std::string> answer;
  std::vector<std::string> listToAdd;

  answer.clear();
  for (unsigned int counter = 0; counter < listSize; ++counter)
    {
      answer = this->requestForPlugin(this->requestsList[counter], pluginsManagers);
      if (answer.size() > 0)
	for (unsigned int counter2 = 0; counter2 < answer.size(); ++counter2)
	    listToAdd.push_back(answer[counter2]);
    }
  
  if (listToAdd.size() > 0)
    {
      this->requestsList.clear();
      listSize = listToAdd.size();
      for (unsigned int counter = 0; counter < listSize; ++counter)
	{
	  Request	requestToAdd(listToAdd[counter]);
	  this->requestsList.push_back(requestToAdd);
	}
      listToAdd.clear();
      this->requestsMaker(pluginsManagers);
    }
}
