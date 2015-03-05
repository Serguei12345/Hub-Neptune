//
// Containers.cpp for ecosysteme in /home/ovoyan_s/rendu/ECOSYSTEME
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Thu May  1 23:24:26 2014 ovoyan_s
// Last update Thu Feb 12 20:19:58 2015 ovoyan_s
//

/*
**					MY INCLUDES
*/

#include				"../headers/Containers.hpp"

/*
**					MY STRING CLASS
*/

MyString::MyString()
{
  this->clear();
  this->random.Srandom();
}

MyString::MyString(const std::string &string_to_set)
{
  this->assign(string_to_set);
  this->random.Srandom();
}

MyString				&MyString::operator=(const std::string &string_to_set)
{
  this->assign(string_to_set);
  return (*this);
}

void					MyString::SetString(const std::string &string_to_set)
{
  this->assign(string_to_set);
}

void					MyString::StrReplaceAll(const std::string &string_to_change,
									const std::string &string_to_set)
{
  size_t				counter;

  counter = 0;
  while ((counter = this->find(string_to_change)) != std::string::npos
	 && counter < this->size())
    this->replace(counter, string_to_change.size(), string_to_set);
}

void					MyString::PushBack(const std::string &string_to_change)
{
  this->assign(string_to_change + *this);
}

void					MyString::RandomString(int string_size)
{
  char					c;
  int					counter;

  c = '\0';
  this->clear();
  counter = 0;
  while (counter < string_size)
    {
      c = static_cast<char>((this->random.GetRandomRN(94)) + 32);
      if (c == '\0')
	c = c + 1;
      this->append(&c);
      counter = counter + 1;
    }
}

void					MyString::RandomStringWithIndex(int string_size, int random_index)
{
  char					c;
  int					counter;

  c = '\0';
  random_index %= (256 - 32);
  this->clear();
  counter = 0;
  while (counter < string_size)
    {
      c = static_cast<char>((this->random.GetRandomRN(random_index)) + 32);
      if (c == '\0')
	c = c + 1;
      this->append(&c);
      counter = counter + 1;
    }
}

void					MyString::RandomNumberString(int string_size, int random_index)
{
  char					c;
  int					counter;

  c = '\0';
  random_index %= 10;
  this->clear();
  counter = 0;
  while (counter < string_size)
    {
      c = static_cast<char>((this->random.GetRandomRN(random_index)));
      c = (c + '0') % 256;
      *this = *this + c;
      counter = counter + 1;
    }
}

int					MyString::NbOfWords()
{
  int					counter;
  int					word_counter;

  counter = 0;
  word_counter = 0;
  if (this->size() == 0)
    return (0);
  while (counter < static_cast<int>(this->size()))
    {
      if ((*this)[counter] == ' ' || (*this)[counter] == '\t')
	{
	  word_counter = word_counter + 1;
	  while (counter < static_cast<int>(this->size()) && ((*this)[counter] == ' '
								 || (*this)[counter] == '\t'))
	    counter = counter + 1;
	}
      counter = counter + 1;
    }
  return (word_counter + 1);
}

std::string                     MyString::StrWordString(const std::string &str_to_use, int *counter,
                                                     char split_char)
{
  std::string                   str_to_ret;
  std::stringstream             stm_to_use;
  std::string                   str_char("");

  while (*counter < static_cast<int>(str_to_use.size()) &&
         str_to_use[*counter] != '\0' && str_to_use[*counter] == split_char)
    *counter = *counter + 1;
  while (*counter < static_cast<int>(str_to_use.size()) &&
         str_to_use[*counter] != '\0' && str_to_use[*counter] != split_char)
    {
      str_char = "";
      stm_to_use.clear();
      if (str_to_use[*counter] != ' ')
        {
          stm_to_use << str_to_use[*counter];
          stm_to_use >> str_char;
          str_to_ret.append(str_char);
        }
      else if (str_to_use[*counter] == ' ')
        {
          str_to_ret.append(" ");
        }
      *counter = *counter + 1;
    }
  return (str_to_ret);
}

void				MyString::StrWordTab(char split_char, MyStringArray *list_to_sent)
{
  int                           counter;
  std::string                   str_to_push("");

  list_to_sent->clear();
  counter = 0;
  while ((*this)[counter] != '\0' && (*this)[counter] == ' ')
    counter = counter + 1;
  if (counter == static_cast<int>(this->size()))
    throw MyException("The command is empty");
  *this = this->substr(counter);
  counter = 0;
  while (counter < static_cast<int>(this->size()))
    {
      str_to_push = this->StrWordString((*this), &counter, split_char);
      if (str_to_push.size() > 0)
        list_to_sent->AddString(str_to_push);
    }
}

std::string			MyString::GetSectionOfString(char c, int iterator1, int iterator2)
{
  int				cCounter = 0;
  unsigned int			sizeOfStr = this->size();
  std::string			str_to_ret = "";
  unsigned int			it1 = 0;
  unsigned int			it2 = 0;
  
  for (unsigned int counter = 0; counter < sizeOfStr && cCounter < iterator1; ++counter)
    {
      if ((*this)[counter] == c)
	++cCounter;
      it1 = counter;
    }
  if (iterator1 != 0)
    ++it1;
  for (unsigned int counter = it1; counter < sizeOfStr && cCounter < iterator2; ++counter)
    {
      if ((*this)[counter] == c)
	++cCounter;
      it2 = counter;
    }
  if ((*this)[it2] != '\t')
    ++it2;

  if (it2 == (*this).size() - 1)
    ++it2;
  while (it1 < it2)
    {
      str_to_ret += (*this)[it1];
      ++it1;
    }
  return (str_to_ret);
}

int					MyString::ToInt()
{
  int					counter;

  counter = 0;
  if (((*this)[counter] != '-' || (*this)[counter] != '+')
      && ((*this)[counter] > '9' || (*this)[counter] < '0'))
    throw MyException("ToInt failure");
  if (((*this)[counter] == '-' || (*this)[counter] == '+')
      && this->size() == 1)
    throw MyException("ToInt failure");
  counter = 1;
  while (counter < static_cast<int>(this->size()))
    {
      if ((*this)[counter] < '0' || (*this)[counter] > '9')
	throw MyException("ToInt failure");
      counter = counter + 1;
    }
  return (atoi(this->c_str()));
}

double					MyString::ToDouble()
{
  int					counter;
  int					point_counter;

  counter = 0;
  point_counter = 0;
  if (((*this)[counter] != '-' || (*this)[counter] != '+')
      && ((*this)[counter] > '9' || (*this)[counter] < '0'))
    throw MyException("ToDouble failure");
  if (((*this)[counter] == '-' || (*this)[counter] == '+')
      && this->size() == 1)
    throw MyException("ToDouble failure");
  counter = 1;
  while (counter < static_cast<int>(this->size()))
    {
      if ((*this)[counter] == '.')
	point_counter = point_counter + 1;
      if (point_counter > 1)
	throw MyException("ToDouble failure");
      if ((*this)[counter] < '0' || (*this)[counter] > '9')
	throw MyException("ToDouble failure");
      counter = counter + 1;
    }
  return (atof(this->c_str()));
}

int					MyString::GetOccurences(const std::string &string_of_occurence)
{
  size_t				counter;
  std::string				str_to_use;
  int					counter_2;

  counter = 0;
  str_to_use = *this;
  counter_2 = 0;
  while ((counter = str_to_use.find(string_of_occurence)) != std::string::npos
	 && counter < str_to_use.size())
    {
      counter_2 = counter_2 + 1;
      str_to_use.replace(counter, string_of_occurence.size(), "");
    }
  return (counter_2);
}

MyString::~MyString()
{

}

/*
**					MY STRING ARRAY CLASS
*/

MyStringArray::MyStringArray()
{
  this->clear();
}

MyStringArray::MyStringArray(const std::list<std::string> &string_array_to_set)
{ 
  this->clear();
  *this = string_array_to_set;
}

MyStringArray				&MyStringArray::operator=(const MyStringArray
								  &string_array_to_set)
{
  static_cast<std::list<std::string> >(*this = string_array_to_set.GetStringArray());
  return (*this);
}

MyStringArray				&MyStringArray::operator=(const std::list<std::string>
									  &string_array_to_set)
{
  static_cast<std::list<std::string> >(*this = string_array_to_set);
  return (*this);
}

void					MyStringArray::SetStringArray(const MyStringArray &sa_to_set)
{
  static_cast<std::list<std::string> >(*this = sa_to_set.GetStringArray());
}

void					MyStringArray::SetStringArray(const std::list<std::string>
									      &string_array_to_set)
{
  static_cast<std::list<std::string> >(*this = string_array_to_set);
}

void					MyStringArray::SetRandomStringArray(int x_size, int y_size,
										    int random_index)
{
  int					counter_y;
  MyString				string_to_insert;

  this->clear();
  counter_y = 0;
  while (counter_y < y_size)
    {
      string_to_insert.RandomNumberString(x_size, random_index);
      this->push_back(string_to_insert);
      counter_y = counter_y + 1;
    }
}

std::string				MyStringArray::GetStringAt(int index) const
{
  std::list<std::string>::iterator	it;
  int					counter;

  it = ((std::list<std::string>*)this)->begin();
  counter = 0;
  while (it != this->end())
    {
      if (counter == index)
	return (*it);
      counter = counter + 1;
      ++it;
    }
  return ("");
}

char					MyStringArray::GetCharAt(unsigned int str_index,
								 unsigned int char_index) const
{
  return (this->GetStringAt(str_index)[char_index]);
}

void					MyStringArray::SetCharAt(unsigned int str_index,
								 unsigned int char_index,
								 unsigned char charToChange)
{
  std::string				strToUse;

  strToUse = this->GetStringAt(str_index);
  if (char_index > strToUse.size() - 1)
    strToUse[char_index] = charToChange;
}

void					MyStringArray::AddString(const std::string &str_to_add)
{
  this->push_back(str_to_add);
}

void					MyStringArray::AddString2(const std::string &str_to_add)
{
  this->push_front(str_to_add);
}

void					MyStringArray::Show()
{
  std::list<std::string>::iterator	it;
  
  it = this->begin();
  while (it != this->end())
    {
      std::cout << *it << std::endl;
      ++it;
    }  
}

std::list<std::string>			MyStringArray::GetStringArray() const
{
  return (*this);
}

MyStringArray::~MyStringArray()
{

}
