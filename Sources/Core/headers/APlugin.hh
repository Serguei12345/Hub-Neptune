//
// APlugin.hh for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Sources/Plugins/APlugin
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 19:34:06 2015 ovoyan_s
// Last update Thu Feb 12 18:43:50 2015 ovoyan_s
//

#ifndef			APLUGIN_HH_
# define		APLUGIN_HH_

# include		<iostream>

class			APlugin
{
private:
  unsigned int		orderNumber;

public:
  APlugin();
  ~APlugin();

  virtual void		initialisation() = 0;
  virtual std::string	update() = 0;
  virtual std::string	doRequest(const std::string& request) = 0;
};

#endif			/*	APLUGIN_HH_	*/
