//
// FileManager.cpp for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Tools/sources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 17:05:44 2015 ovoyan_s
// Last update Fri Mar 20 12:59:34 2015 ovoyan_s
//

#include		"FileManager.hh"

FileManager::FileManager()
{
}

FileManager::~FileManager()
{

}

void		FileManager::loadFile(const std::string &pathOfFile)
{
  this->file.loadFile(pathOfFile);
}

std::vector<std::string>		&FileManager::getContent() const
{
  return (const_cast<std::vector<std::string>&>(this->file.getLinesOfFile()));
}

std::map<std::string, std::vector<std::string> >	FileManager::getConfigContent()
{
  std::map<std::string, std::vector<std::string> >	mapToRet;
  unsigned int				size = this->file.getLinesOfFile().size();

  for (unsigned int counter = 0; counter < size; ++counter)
    {
      std::pair<std::string, std::vector<std::string> > pairToAdd
	= this->getPairAtString(this->file.getLinesOfFile()[counter]);
      mapToRet.insert(pairToAdd);
    } 
  return (mapToRet);
}

std::pair<std::string, std::vector<std::string> > FileManager::getPairAtString(const std::string& strToUse)
{
  MyString				element = strToUse;

  if (element.GetOccurences(element) != 1)
    throw (MyException("Invalid element"));
  std::string firstElement = element.GetSectionOfString('\t', 0, 1);

  std::vector<std::string> secondElement;
  secondElement.push_back(element.GetSectionOfString('\t', 1, 2));
  secondElement.push_back(element.GetSectionOfString('\t', 2, 3));

  std::pair<std::string, std::vector<std::string> >	pairToRet(firstElement, secondElement);
  return (pairToRet);
}
