//
// FileManager.hh for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Tools/headers
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 17:05:25 2015 ovoyan_s
// Last update Thu Feb 12 19:32:54 2015 ovoyan_s
//

#ifndef			FILE_MANAGER_HH_
# define		FILE_MANAGER_HH_

# include		<fstream>
# include		<iostream>
# include		<map>
# include		<sstream>
# include		<vector>

# include		"Containers.hpp"
# include		"MyException.hh"

class			FileManager
{
private:
  std::vector<std::string>	linesOfFile;
  unsigned int			sizeOfFile;
  std::string			pathOfFile;
  std::string			nameOfFile;
  std::string			extensionOfFile;

  bool					findNameOfFile(const std::string& pathOfFile);
  bool					findExtensionOfFile(const std::string& pathOfFile);
  std::pair<std::string, std::vector<std::string> >	getPairAtString(const std::string& strToUse);

public:
  FileManager();
  ~FileManager();

  void					loadFile(const std::string &pathOfFile);

  std::vector<std::string>		&getContent() const;
  std::map<std::string, std::vector<std::string> >	getConfigContent();

  std::string				getPathOfFile() const;
  std::string				getNameOfFile() const;
  std::string				getExtensionOfFile() const;
};

#endif			/*	FILE_MANAGER_HH_	*/
