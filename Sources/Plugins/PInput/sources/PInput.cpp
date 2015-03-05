//
// PInput.cpp for PInput in /home/ovoyan_s/Hub-Neptune/Sources/Plugins/PInputs
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon Mar  2 18:25:16 2015 ovoyan_s
// Last update Thu Mar  5 19:33:20 2015 ovoyan_s
//

#include		"PInput.hh"

PInput::PInput()
{
  std::cout << "PInput Created" << std::endl;
}

PInput::~PInput()
{
}

void			PInput::initialisation()
{
  this->sdlEvents = new SDL_Event();
}

std::string		PInput::vecIntToString(const std::vector<int> &vInt)
{
  std::string		strToRet = "";
  std::stringstream	stmToUse;
  std::string		strToUse;
  unsigned int		vIntSize = vInt.size();

  for (unsigned int counter = 0; counter < vIntSize; ++counter)
    {
      strToUse = "";
      stmToUse << vInt[counter];
      stmToUse >> strToUse;
      if (strToRet.size() == 0)
	strToRet += ('T' + strToUse);
      else
	strToRet += (" T" + strToUse);
    }
  strToRet = "PGraph\t" + strToRet;
  return (strToRet);
}

std::vector<std::string>	PInput::update()
{
  std::vector<int>		vectorOfEvents;
  std::vector<std::string>	vectorToSend;

  vectorOfEvents = this->events.basicEvents(this->sdlEvents);
  if (vectorOfEvents.size() > 0)
    vectorToSend.push_back(this->vecIntToString(vectorOfEvents));
  return (vectorToSend);
}

std::vector<std::string>	PInput::doRequest(const std::string& request)
{
  std::vector<std::string>	test;

  (void)request;
  test.clear();
  return (test);
}

extern "C"
{
  PInput*		retPlugin()
  {
    return (new PInput());
  }
}
