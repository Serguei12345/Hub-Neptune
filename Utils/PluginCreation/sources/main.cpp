//
// main.cpp for PluginCreation in /home/ovoyan_s/Hub-Neptune/Utils/PluginCreation
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Thu Mar 19 14:34:32 2015 ovoyan_s
// Last update Fri Mar 20 16:36:26 2015 ovoyan_s
//

#include		"main.hh"

std::string		vecToString(const std::vector<std::string>& vecToTransform)
{
  std::string		mc = "";
  unsigned int		size = vecToTransform.size();

  for (unsigned int cb = 0; cb < size; ++cb)
    mc += vecToTransform[cb] + '\n';
  return (mc);
}

void			creationOfHeaderFiles(const std::string& pluginName,
					      const std::string& className)
{
  File aPluginToCopy("Model/headers/APlugin.hh");
  MyString ms = vecToString(aPluginToCopy.getLinesOfFile());
  ms.StrReplaceAll("PluginName", pluginName);
  ms.StrReplaceAll("ClassName", className);

  File aPluginToCreate(pluginName + "/headers/APlugin.hh");
  aPluginToCreate.writeOnFile(ms, FileManagement::Append);

  File classHeaderToCopy("Model/headers/ClassName.hh");
  ms = vecToString(classHeaderToCopy.getLinesOfFile());
  ms.StrReplaceAll("PluginName", pluginName);
  ms.StrReplaceAll("ClassName", className);

  File classHeaderToCreate(pluginName + "/headers/" + className + ".hh");
  classHeaderToCreate.writeOnFile(ms, FileManagement::Append);
}

void			creationOfSourceFiles(const std::string& pluginName,
					      const std::string& className)
{
  File aPluginToCopy("Model/sources/APlugin.cpp");
  MyString ms = vecToString(aPluginToCopy.getLinesOfFile());
  ms.StrReplaceAll("PluginName", pluginName);
  ms.StrReplaceAll("ClassName", className);

  File aPluginToCreate(pluginName + "/sources/APlugin.cpp");
  aPluginToCreate.writeOnFile(ms, FileManagement::Append);

  File classHeaderToCopy("Model/sources/ClassName.cpp");
  ms = vecToString(classHeaderToCopy.getLinesOfFile());
  ms.StrReplaceAll("PluginName", pluginName);
  ms.StrReplaceAll("ClassName", className);

  File classHeaderToCreate(pluginName + "/sources/" + className + ".cpp");
  classHeaderToCreate.writeOnFile(ms, FileManagement::Append);
}

void			creationOfRepertories(const std::string& pluginName)
{
  std::string		sources = pluginName + "/sources"; 
  std::string		headers = pluginName + "/headers"; 

  mkdir((char*)pluginName.c_str(), 0777);
  mkdir((char*)sources.c_str(), 0777);
  mkdir((char*)headers.c_str(), 0777);
}

void			creationOfMakefile(const std::string& pluginName,
					   const std::string& className)
{
  File fileToCopy("Model/Makefile");
  MyString ms = vecToString(fileToCopy.getLinesOfFile());
  ms.StrReplaceAll("PluginName", pluginName);
  ms.StrReplaceAll("ClassName", className);

  File fileToCreate(pluginName + "/Makefile");
  fileToCreate.writeOnFile(ms, FileManagement::Append);
}

int			main()
{
  std::string pluginName = "";
  std::string className = "";

  std::cout << "Hello and welcome to the plugin creation manager : " << std::endl;
  std::cout << "Choose a name for your plugin : ";
  std::cin >> pluginName;
  std::cout << "Choose a name for your class : ";
  std::cin >> className;

  creationOfRepertories(pluginName);
  creationOfMakefile(pluginName, className);
  creationOfHeaderFiles(pluginName, className);
  creationOfSourceFiles(pluginName, className);

  return (0);
}
