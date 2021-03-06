//
// File.cpp for Ecosystem in /home/ovoyan_s/Hub-Neptune/Sources/Tools
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Fri Mar 20 12:36:48 2015 ovoyan_s
// Last update Fri Mar 20 16:14:13 2015 ovoyan_s
//

#include		"File.hh"

File::File()
{

}

File::File(const std::string& pathOfFile)
{
  this->loadFile(pathOfFile);
}

void		File::loadFile(const std::string& pathOfFile)
{
  std::string           strToUse = "";
  std::ifstream         fileStream;

  fileStream.open((char*)pathOfFile.c_str(), std::fstream::in | std::fstream::app);
  if (fileStream.good() == false)
    throw (MyException("The loaded file is not good"));
  fileStream.seekg(0, std::ios::end);
  this->sizeOfFile = fileStream.tellg();
  fileStream.seekg(0, std::ios::beg);

  this->linesOfFile.clear();
  this->pathOfFile = pathOfFile;

  this->findNameOfFile(pathOfFile);
  this->findExtensionOfFile(pathOfFile);

  while (std::getline(fileStream, strToUse))
    this->linesOfFile.push_back(strToUse);
  if (this->findNameOfFile(pathOfFile) == false || this->findExtensionOfFile(pathOfFile) == false)
    throw (MyException("The loaded file is not good"));
  fileStream.close();
}

void		File::unloadFile()
{
  this->pathOfFile = "";
  this->nameOfFile = "";
  this->extensionOfFile = "";
  this->sizeOfFile = 0;
  this->linesOfFile.clear();
}

void		File::writeOnFile(const std::string& textToWrite,
				  const FileManagement::OpenningMode& mode)
{
  std::ofstream	fileStream;
  
  if (mode == FileManagement::Append)
    fileStream.open((char*)this->pathOfFile.c_str(), std::ios::app);
  else
    fileStream.open((char*)this->pathOfFile.c_str(), std::ios::trunc);
  fileStream << textToWrite << std::endl;
  fileStream.close();
}

std::string&	File::getPathOfFile() const
{
  return (const_cast<std::string&>(this->pathOfFile));
}

std::string&	File::getNameOfFile() const
{
  return (const_cast<std::string&>(this->nameOfFile));
}

std::string&	File::getExtensionOfFile() const
{
  return (const_cast<std::string&>(this->extensionOfFile));
}

unsigned int&	File::getSizeOfFile() const
{
  return (const_cast<unsigned int&>(this->sizeOfFile));
}

std::vector<std::string>&	File::getLinesOfFile() const
{
  return (const_cast<std::vector<std::string>& >(this->linesOfFile));
}

bool            File::findNameOfFile(const std::string& pathOfFile)
{
  size_t        lastSlash = pathOfFile.find_last_of("/");
  size_t        lastPoint = pathOfFile.find_last_of(".");

  if (lastSlash == std::string::npos)
    lastSlash = 0;
  if (lastPoint == std::string::npos)
    lastPoint = pathOfFile.size();
  if (lastSlash >= lastPoint)
    return (false);

  if (lastSlash == 0)
    this->nameOfFile = pathOfFile.substr(lastSlash, lastPoint - lastSlash);
  else
    this->nameOfFile = pathOfFile.substr(lastSlash + 1, lastPoint - lastSlash - 1);
  return (true);
}

bool            File::findExtensionOfFile(const std::string& pathOfFile)
{
  size_t        lastPoint = pathOfFile.find_last_of(".");

  if (lastPoint == std::string::npos)
    this->extensionOfFile = "";
  else
    this->extensionOfFile = pathOfFile.substr(lastPoint + 1, pathOfFile.size() - lastPoint - 1);
  return (true);
}
