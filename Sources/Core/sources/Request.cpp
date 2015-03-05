//
// Request.cpp for Neptune in /home/ovoyan_s/Hub-Neptune/Sources/Core
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon Mar  2 18:38:15 2015 ovoyan_s
// Last update Thu Mar  5 17:38:18 2015 ovoyan_s
//

#include	"Request.hh"

Request::Request()
{

}

Request::Request(const std::string &requestToAdd)
{
  this->request = requestToAdd;
}

Request::~Request()
{

}

std::string	&Request::getRequest() const
{
  return (const_cast<std::string&>(this->request));
}
