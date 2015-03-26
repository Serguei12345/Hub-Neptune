#include		"ClassName.hh"

ClassName::ClassName()
{
  std::cout << "PGraph Created" << std::endl;
}

ClassName::~ClassName()
{

}

void			ClassName::initialisation(const std::string& configFile)
{
  (void)configFile;
}

std::vector<std::string>	ClassName::update()
{
  std::vector<std::string>	test;

  test.clear();
  return (test);
}

std::vector<std::string>	ClassName::doRequest(const std::string& request)
{
  std::vector<std::string>	test;

  test.clear();
  (void)request;
  return (test);
}

extern "C"
{
  ClassName*		retPlugin()
  {
    return (new ClassName());
  }
}
