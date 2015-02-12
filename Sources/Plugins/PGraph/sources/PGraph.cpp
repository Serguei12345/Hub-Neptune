//
// PGraph.cpp for PGraph in /home/ovoyan_s/Hub-Neptune/Sources/Plugins/PGraph
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 20:35:23 2015 ovoyan_s
// Last update Tue Feb 10 12:29:03 2015 ovoyan_s
//

#include		"PGraph.hh"

PGraph::PGraph()
{
  std::cout << "PGraph Created" << std::endl;
}

PGraph::~PGraph()
{

}

void			PGraph::initialisation()
{
  std::cout << "initialisation" << std::endl;
}

std::string		PGraph::update()
{
  std::cout << "SWAG" << std::endl;
  return ("");
}

std::string		PGraph::doRequest(const std::string& request)
{
  (void)request;
  return ("");
}

extern "C"
{
  PGraph*		retPlugin()
  {
    return (new PGraph());
  }
}
