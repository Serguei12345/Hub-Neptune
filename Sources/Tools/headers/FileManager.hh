//
// FileManager.hh for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Tools/headers
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 17:05:25 2015 ovoyan_s
// Last update Fri Mar 20 12:59:29 2015 ovoyan_s
//

#ifndef			FILE_MANAGER_HH_
# define		FILE_MANAGER_HH_

# include		<fstream>
# include		<iostream>
# include		<map>
# include		<sstream>
# include		<vector>

# include		"Containers.hpp"
# include		"File.hh"
# include		"MyException.hh"

class			FileManager
{
private:
  File			file;

  bool					findNameOfFile(const std::string& pathOfFile);
  bool					findExtensionOfFile(const std::string& pathOfFile);
  std::pair<std::string, std::vector<std::string> >	getPairAtString(const std::string& strToUse);

public:
  FileManager();
  ~FileManager();

  void					loadFile(const std::string &pathOfFile);

  std::vector<std::string>		&getContent() const;
  std::map<std::string, std::vector<std::string> >	getConfigContent();

};

#endif			/*	FILE_MANAGER_HH_	*/
