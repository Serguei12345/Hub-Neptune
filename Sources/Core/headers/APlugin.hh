//
// APlugin.hh for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Sources/Plugins/APlugin
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 19:34:06 2015 ovoyan_s
// Last update Thu Mar  5 17:10:32 2015 ovoyan_s
//

#ifndef			APLUGIN_HH_
# define		APLUGIN_HH_

# include		<iostream>
# include		<vector>

class			APlugin
{
private:
  unsigned int		orderNumber;

public:
  APlugin();
  ~APlugin();

  virtual void				initialisation(const std::string& configFile) = 0;
  virtual std::vector<std::string>	update() = 0;
  virtual std::vector<std::string>	doRequest(const std::string& request) = 0;
};

#endif			/*	APLUGIN_HH_	*/
