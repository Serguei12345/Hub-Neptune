//
// EventActions.hh for Ecosysteme in /home/ovoyan_s/Loisirs/Ecosysteme
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Thu Sep 18 15:40:51 2014 ovoyan_s
// Last update Thu Mar  5 20:13:42 2015 ovoyan_s
//

#ifndef		EVENT_ACTIONS_HH_
# define	EVENT_ACTIONS_HH_

/*
**			General Includes
*/

# include	<iostream>
# include	<SDL/SDL.h>
# include	<vector>

/*
**			My Includes
*/

class		EventActions
{
private:
  bool          (EventActions::*meths[24])(void* data);

public:
  EventActions();
  ~EventActions();

  bool	        playCommands(int actions, void* data);

  //				Arrow Keys

  bool          right(void*);
  bool          left(void*);
  bool          up(void*);
  bool          down(void*);

  //				Mouse Mapping

  bool          wheelMore(void*);
  bool          wheelLess(void*);
  bool		moveMouseLeft(void*);
  bool		moveMouseRight(void*);

  //				General Keys

  bool          quit(void*);
  bool          escape(void*);

  //				Numpad Keys

  bool		num2(void*);
  bool		num4(void*);
  bool		num6(void*);
  bool		num8(void*);
  bool		num0(void*);

  //				Keyboard Keys

  bool		letterA(void*);
  bool		letterZ(void*);
  bool		letterQ(void*);
  bool		letterS(void*);
  bool		letterE(void*);
  bool		letterR(void*);
  bool		letterD(void*);
  bool		letterF(void*);
  bool		letterC(void*);
};

#endif			/*	EVENT_ACTIONS_HH_	*/
