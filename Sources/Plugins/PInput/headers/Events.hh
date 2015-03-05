//
// Events.hh for Ecosysteme in /home/ovoyan_s/Loisirs/Ecosysteme
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Sep 17 19:32:16 2014 ovoyan_s
// Last update Sun Nov 16 16:50:13 2014 ovoyan_s
//

#ifndef				EVENTS_HH_
# define			EVENTS_HH_

/*
**				General Includes
*/

# include			<iostream>
# include			<SDL/SDL.h>
# include			<string>
# include			<vector>

/*
**				My Includes
*/

# include			"MyException.hh"

class				MyEvents
{
private:
  bool				(MyEvents::*meths[24])(SDL_Event *event);
public:
  MyEvents();
  ~MyEvents();

  std::vector<int>		basicEvents(SDL_Event *event);

  //				Arrow Keys

  bool				right(SDL_Event *event);
  bool				left(SDL_Event *event);
  bool				up(SDL_Event *event);
  bool				down(SDL_Event *event);

  //				Mouse Mapping

  bool				wheelMore(SDL_Event *event);
  bool				wheelLess(SDL_Event *event);
  bool				mouseMotionLeft(SDL_Event *event);
  bool				mouseMotionRight(SDL_Event *event);

  //				General Keys

  bool				quit(SDL_Event *event);
  bool				escape(SDL_Event *event);

  //				Numpad

  bool				num2(SDL_Event *event);
  bool				num4(SDL_Event *event);
  bool				num6(SDL_Event *event);
  bool				num8(SDL_Event *event);
  bool				num0(SDL_Event *event);

  //				KeyBoad Keys

  bool				letterA(SDL_Event *event);
  bool				letterZ(SDL_Event *event);
  bool				letterQ(SDL_Event *event);
  bool				letterS(SDL_Event *event);
  bool				letterE(SDL_Event *event);
  bool				letterR(SDL_Event *event);
  bool				letterD(SDL_Event *event);
  bool				letterF(SDL_Event *event);
  bool				letterC(SDL_Event *event);
};

#endif				/*	EVENTS_HH_	*/
