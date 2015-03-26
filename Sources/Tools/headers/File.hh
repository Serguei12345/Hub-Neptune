//
// File.hh for Ecosystem in /home/ovoyan_s/Hub-Neptune/Sources/Tools
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Fri Mar 20 12:37:02 2015 ovoyan_s
// Last update Fri Mar 20 13:18:15 2015 ovoyan_s
//

#ifndef			FILE_HH_
# define		FILE_HH_

# include		<fstream>
# include		<iostream>
# include		<vector>

# include		"MyException.hh"

namespace		FileManagement
{
enum			OpenningMode
  {
    Append,
    Truncate
  };
}

class			File
{
private:
  std::string			pathOfFile;
  std::string			nameOfFile;
  std::string			extensionOfFile;
  unsigned int			sizeOfFile;
  std::vector<std::string>	linesOfFile;

public:

  File();
  File(const std::string& pathOfFile);

  void				loadFile(const std::string& pathOfFile);
  void				unloadFile();

  void				writeOnFile(const std::string& textToWrite,
					    const FileManagement::OpenningMode& mode);

  std::string&			getPathOfFile() const;
  std::string&			getNameOfFile() const;
  std::string&			getExtensionOfFile() const;
  unsigned int&			getSizeOfFile() const;
  std::vector<std::string>&	getLinesOfFile() const;

  bool				findNameOfFile(const std::string& pathOfFile);
  bool				findExtensionOfFile(const std::string& pathOfFile);
};

#endif			/*	FILE_HH_	*/
