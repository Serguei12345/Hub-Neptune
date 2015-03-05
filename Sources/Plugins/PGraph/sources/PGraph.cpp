//
// PGraph.cpp for PGraph in /home/ovoyan_s/Hub-Neptune/Sources/Plugins/PGraph
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 20:35:23 2015 ovoyan_s
// Last update Thu Mar  5 20:40:06 2015 ovoyan_s
//

#include		"PGraph.hh"

PGraph::PGraph()
{
  std::cout << "PGraph Created" << std::endl;
}

PGraph::~PGraph()
{

}

void			PGraph::initialisation(const std::string& configFile)
{
  (void)configFile;
  FileManager		fm;
  SDL_Surface		*fenetre;
  
  Random::Srandom();
  fm.loadFile(configFile);
  this->configMap = fm.getConfigContent();
  try
    {
      if (this->configMap["SIZE"].size() != 2 || atoi((char*)this->configMap["SIZE"][0].c_str()),
	  atoi((char*)this->configMap["SIZE"][1].c_str()) <= 0)
	throw (MyException ("La création de la fenetre a échoué"));
      if (SDL_Init(SDL_INIT_VIDEO) < 0
	  || (fenetre = SDL_SetVideoMode(atoi((char*)this->configMap["SIZE"][0].c_str()),
					 atoi((char*)this->configMap["SIZE"][1].c_str()),
								      32, SDL_OPENGL)) == NULL)
	throw (MyException ("Erreur initialisation SDL"));
    }
  catch (MyException const &e)
    {
      std::cout << e.what() << std::endl;
    }
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

  test.clear();
  if (request[0] == 'T')
    {
      std::stringstream		stmToUse;
      unsigned int		commandNumber = 0;
      std::string touch = ((MyString)request).GetSectionOfString('T', 1, 2);
      stmToUse << touch;
      stmToUse >> commandNumber;
      if (this->eventActions.playCommands(commandNumber, NULL) == false)
	test.push_back("QUIT");
    }
  return (test);
}

extern "C"
{
  PGraph*		retPlugin()
  {
    return (new PGraph());
  }
}
