//
// FileManager.hh for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Tools/headers
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 17:05:25 2015 ovoyan_s
// Last update Wed Feb  4 17:37:14 2015 ovoyan_s
//

#ifndef			FILE_MANAGER_HH_
# define		FILE_MANAGER_HH_

# include		<fstream>
# include		<iostream>

class			FileManager
{
private:
  std::fstream		oFileToUse;
  FileManager();
  
public:
  FileManager(const std::string &pathOfFile);
  ~FileManager();

  std::string		getContent();
  void			addContentAtEnd(const std::string &stringToAdd);
};

#endif			/*	FILE_MANAGER_HH_	*/
