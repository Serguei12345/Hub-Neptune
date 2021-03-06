//
// PInput.hh for PInput in /home/ovoyan_s/Hub-Neptune/Sources/Plugins/PInputs
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Mon Mar  2 18:24:27 2015 ovoyan_s
// Last update Thu Mar  5 19:24:55 2015 ovoyan_s
//

#ifndef			PINPUT_HH_
# define		PINPUT_HH_

# include		<iostream>
# include		<SDL/SDL.h>
# include		<sstream>

# include		"APlugin.hh"
# include		"Events.hh"

class			PInput : public APlugin
{
private:
  MyEvents		events;
  SDL_Event		*sdlEvents;

public:
  PInput();
  ~PInput();

  void				initialisation();
  std::string			vecIntToString(const std::vector<int> &vInt);
  std::vector<std::string>	update();
  std::vector<std::string>	doRequest(const std::string& request);
};

#endif			/*	PGRAPH_HH_	*/
