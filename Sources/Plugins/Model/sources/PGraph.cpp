//
// PGraph.cpp for PGraph in /home/ovoyan_s/Hub-Neptune/Sources/Plugins/PGraph
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 20:35:23 2015 ovoyan_s
// Last update Thu Mar  5 17:06:31 2015 ovoyan_s
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

std::vector<std::string>	PGraph::update()
{
  std::vector<std::string>	test;

  test.clear();
  return (test);
}

std::vector<std::string>	PGraph::doRequest(const std::string& request)
{
  std::vector<std::string>	test;

  (void)request;
  test.clear();
  return (test);
}

extern "C"
{
  PGraph*		retPlugin()
  {
    return (new PGraph());
  }
}
