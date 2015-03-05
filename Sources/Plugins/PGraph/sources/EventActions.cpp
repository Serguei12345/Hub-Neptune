//
// EventActions.cpp for Ecosysteme in /home/ovoyan_s/Loisirs/Ecosysteme
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Thu Sep 18 15:43:15 2014 ovoyan_s
// Last update Thu Mar  5 20:36:46 2015 ovoyan_s
//

/*
**			My Includes
*/

#include                "EventActions.hh"

EventActions::EventActions()
{
  this->meths[0] = &EventActions::right;
  this->meths[1] = &EventActions::left;
  this->meths[2] = &EventActions::up;
  this->meths[3] = &EventActions::down;
  this->meths[4] = &EventActions::wheelMore;
  this->meths[5] = &EventActions::wheelLess;
  this->meths[6] = &EventActions::quit;
  this->meths[7] = &EventActions::escape;
  this->meths[8] = &EventActions::moveMouseLeft;
  this->meths[9] = &EventActions::moveMouseRight;
  this->meths[10] = &EventActions::num2;
  this->meths[11] = &EventActions::num4;
  this->meths[12] = &EventActions::num6;
  this->meths[13] = &EventActions::num8;
  this->meths[14] = &EventActions::num0;
  this->meths[15] = &EventActions::letterA;
  this->meths[16] = &EventActions::letterZ;
  this->meths[17] = &EventActions::letterQ;
  this->meths[18] = &EventActions::letterS;
  this->meths[19] = &EventActions::letterE;
  this->meths[20] = &EventActions::letterR;
  this->meths[21] = &EventActions::letterD;
  this->meths[22] = &EventActions::letterF;
  this->meths[23] = &EventActions::letterC;
}

EventActions::~EventActions()
{

}

bool			EventActions::playCommands(int commandsToPlay, void* data)
{
  if ((this->*meths[commandsToPlay])(data) == false)
    return (false);
  return (true);
}

bool                    EventActions::right(void*)
{
  return (true);
}

bool                    EventActions::left(void*)
{
  return (true);
}

bool                    EventActions::up(void*)
{
  return (true);
}

bool                    EventActions::down(void*)
{
  return (true);
}

bool                    EventActions::wheelMore(void*)
{
  return (true);
}

bool                    EventActions::wheelLess(void*)
{
  return (true);
}

bool                    EventActions::quit(void*)
{
  return (false);
}

bool                    EventActions::escape(void*)
{
  return (false);
}

bool			EventActions::moveMouseLeft(void*)
{
  return (true);
}

bool			EventActions::moveMouseRight(void*)
{
  return (true);
}

bool			EventActions::num2(void*)
{
  return (true);
}

bool			EventActions::num4(void*)
{
  return (true);
}

bool			EventActions::num6(void*)
{
  return (true);
}

bool			EventActions::num8(void*)
{
  return (true);
}

bool			EventActions::num0(void*)
{
  return (true);
}

bool			EventActions::letterA(void*)
{
  return (true);
}

bool			EventActions::letterZ(void*)
{
  return (true);
}

bool			EventActions::letterQ(void*)
{
  return (true);
}

bool			EventActions::letterS(void*)
{
  return (true);
}

bool			EventActions::letterE(void*)
{
  return (true);
}

bool			EventActions::letterR(void*)
{
  return (true);
}

bool			EventActions::letterD(void*)
{
  return (true);
}

bool			EventActions::letterF(void*)
{
  return (true);
}

bool			EventActions::letterC(void*)
					      
{
  return (true);
}
