//
// main.cpp for Ecosysteme in /home/ovoyan_s/Hub-Neptune
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 16:58:18 2015 ovoyan_s
// Last update Mon Feb  9 18:09:40 2015 ovoyan_s
//

#include		"main.hh"


void			initialisation(char **av)
{
  Ecosysteme		ecosystem;

  ecosystem.start(av);
}

int			main(int ac, char **av)
{
  if (ac == 2)
    {
      try
	{
	  initialisation(av);
	}
      catch (std::exception e)
	{
	  std::cout << e.what() << std::endl;
	}
    }
  else
    std::cout << "USAGE : ./ecosysteme [MAIN_CONFIG_FILE]" << std::endl;
  return (0);
}

