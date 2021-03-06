//
// FileManager.cpp for Ecosysteme in /home/ovoyan_s/Hub-Neptune/Tools/sources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Feb  4 17:05:44 2015 ovoyan_s
// Last update Thu Feb 12 20:32:44 2015 ovoyan_s
//

#include		"FileManager.hh"

FileManager::FileManager()
{
  this->sizeOfFile = 0;
}

FileManager::~FileManager()
{

}

void		FileManager::loadFile(const std::string &pathOfFile)
{
  std::string		strToUse = "";
  std::ifstream		fileStream;
  
  fileStream.open((char*)pathOfFile.c_str(), std::fstream::in | std::fstream::app);
  if (fileStream.good() == false)
    throw (MyException("The loaded file is not good"));
  fileStream.seekg(0, std::ios::end);
  this->sizeOfFile = fileStream.tellg();
  fileStream.seekg(0, std::ios::beg);
  
  this->linesOfFile.clear();
  while (std::getline(fileStream, strToUse))
    this->linesOfFile.push_back(strToUse);
  if (this->findNameOfFile(pathOfFile) == false || this->findExtensionOfFile(pathOfFile) == false)
    throw (MyException("The loaded file is not good"));
  fileStream.close();
}

bool		FileManager::findNameOfFile(const std::string& pathOfFile)
{
  size_t	lastSlash = pathOfFile.find_last_of("/");
  size_t	lastPoint = pathOfFile.find_last_of(".");

  if (lastSlash == std::string::npos)
    lastSlash = 0;
  if (lastPoint == std::string::npos)
    lastPoint = pathOfFile.size();
  if (lastSlash >= lastPoint)
    return (false);
  this->nameOfFile = pathOfFile.substr(lastSlash + 1, lastPoint - lastSlash - 1);
  return (true);
}

bool		FileManager::findExtensionOfFile(const std::string& pathOfFile)
{
  size_t	lastPoint = pathOfFile.find_last_of(".");

  if (lastPoint == std::string::npos)
    this->extensionOfFile = "";
  else
    this->extensionOfFile = pathOfFile.substr(lastPoint + 1, pathOfFile.size() - lastPoint - 1);
  return (true);
}

std::vector<std::string>		&FileManager::getContent() const
{
  return (const_cast<std::vector<std::string>&>(linesOfFile));
}

std::map<std::string, std::vector<std::string> >	FileManager::getConfigContent()
{
  std::map<std::string, std::vector<std::string> >	mapToRet;
  unsigned int				size = this->linesOfFile.size();

  for (unsigned int counter = 0; counter < size; ++counter)
    {
      std::pair<std::string, std::vector<std::string> > pairToAdd
	= this->getPairAtString(this->linesOfFile[counter]);
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

std::string				FileManager::getPathOfFile() const
{
  return (const_cast<std::string&>(this->pathOfFile));
}

std::string				FileManager::getNameOfFile() const
{
  return (const_cast<std::string&>(this->nameOfFile));
}

std::string				FileManager::getExtensionOfFile() const
{
  return (const_cast<std::string&>(this->extensionOfFile));
}
