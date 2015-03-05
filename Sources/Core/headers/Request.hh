//
// Request.hh for Neptune in /home/ovoyan_s/Hub-Neptune/Sources/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon Mar  2 18:33:26 2015 ovoyan_s
// Last update Thu Mar  5 17:38:23 2015 ovoyan_s
//

#ifndef		REQUEST_HH_
# define	REQUEST_HH_

# include	<iostream>
# include	<string>

class		Request
{
private:
  std::string	request;
public:
  Request();
  Request(const std::string &requestToAdd);
  ~Request();

  std::string	&getRequest() const;
};

#endif		/*	REQUEST_HH_	*/
