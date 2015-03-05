//
// Events.cpp for Ecosysteme in /home/ovoyan_s/Loisirs/Ecosysteme
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Sep 17 19:31:55 2014 ovoyan_s
// Last update Thu Mar  5 20:35:31 2015 ovoyan_s
//

/*
**			My Includes
*/

#include		"Events.hh"

MyEvents::MyEvents()
{
  this->meths[0] = &MyEvents::right;
  this->meths[1] = &MyEvents::left;
  this->meths[2] = &MyEvents::up;
  this->meths[3] = &MyEvents::down;
  this->meths[4] = &MyEvents::wheelMore;
  this->meths[5] = &MyEvents::wheelLess;
  this->meths[6] = &MyEvents::quit;
  this->meths[7] = &MyEvents::escape;
  this->meths[8] = &MyEvents::mouseMotionLeft;
  this->meths[9] = &MyEvents::mouseMotionRight;
  this->meths[10] = &MyEvents::num2;
  this->meths[11] = &MyEvents::num4;
  this->meths[12] = &MyEvents::num6;
  this->meths[13] = &MyEvents::num8;
  this->meths[14] = &MyEvents::num0;
  this->meths[15] = &MyEvents::letterA;
  this->meths[16] = &MyEvents::letterZ;
  this->meths[17] = &MyEvents::letterQ;
  this->meths[18] = &MyEvents::letterS;
  this->meths[19] = &MyEvents::letterE;
  this->meths[20] = &MyEvents::letterR;
  this->meths[21] = &MyEvents::letterD;
  this->meths[22] = &MyEvents::letterF;
  this->meths[23] = &MyEvents::letterC;
}

MyEvents::~MyEvents()
{

}

std::vector<int>	MyEvents::basicEvents(SDL_Event *event)
{
  unsigned int		counter;
  std::vector<int>	listOfEvents;

  SDL_PollEvent(event);
  listOfEvents.clear();
  counter = 0;
  while (counter < 24)
    {
      if ((this->*meths[counter])(event) == true)
	{
	  listOfEvents.push_back(counter);
	}
      ++counter;
    }
  return (listOfEvents);
}

bool			MyEvents::right(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RIGHT)
    return (true);
  return (false);
}

bool			MyEvents::left(SDL_Event *event)
{ 
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_LEFT)
    return (true);
  return (false);
}

bool			MyEvents::up(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_UP)
    return (true);
  return (false);
}

bool			MyEvents::down(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_DOWN)
    return (true);
  return (false);
}

bool			MyEvents::wheelMore(SDL_Event *event)
{
  if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_WHEELUP)
    return (true);
  return (false);
}

bool			MyEvents::wheelLess(SDL_Event *event)
{
  if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_WHEELDOWN)
    return (true);
  return (false);
}

bool			MyEvents::quit(SDL_Event *event)
{
  if (event->type == SDL_QUIT)
    {
      throw MyException("Exit");
      return (true);
    }
  return (false);
}

bool			MyEvents::escape(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
    return (true);
  return (false);
}

bool			MyEvents::mouseMotionLeft(SDL_Event *event)
{
  if (event->type == SDL_MOUSEMOTION)
    {
      if (event->motion.state & SDL_BUTTON_LMASK)
	return (true);
    }
  return (false);
}

bool			MyEvents::mouseMotionRight(SDL_Event *event)
{
  if (event->type == SDL_MOUSEMOTION)
    {
      if (event->motion.state & SDL_BUTTON_RMASK)
	return (true);
    }
  return (false);
}

bool			MyEvents::num2(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_KP2)
    return (true);
  return (false);
}

bool			MyEvents::num4(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_KP4)
    return (true);
  return (false);
}

bool			MyEvents::num6(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_KP6)
    return (true);
  return (false);
}

bool			MyEvents::num8(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_KP8)
    return (true);
  return (false);
}

bool			MyEvents::num0(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_KP0)
    return (true);
  return (false);
}

bool			MyEvents::letterA(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_a)
    return (true);
  return (false);
}

bool			MyEvents::letterZ(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_z)
    return (true);
  return (false);
}

bool			MyEvents::letterQ(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_q)
    return (true);
  return (false);
}

bool			MyEvents::letterS(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_s)
    return (true);
  return (false);
}

bool			MyEvents::letterE(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_e)
    return (true);
  return (false);
}

bool			MyEvents::letterR(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_r)
    return (true);
  return (false);
}

bool			MyEvents::letterD(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_d)
    return (true);
  return (false);
}

bool			MyEvents::letterF(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_f)
    return (true);
  return (false);
}

bool			MyEvents::letterC(SDL_Event *event)
{
  if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_c)
    return (true);
  return (false);
}
