#include "string.hpp"
#include <cctype>

char * mozhegova::inputString(std::istream & in, char stop)
{
  size_t length = 10;
  char * str = nullptr;
  str = new char [length + 1];
  size_t size = 0;
  char next = '\0';
  std::noskipws(in);
  while ((in >> next) && (next != stop))
  {
    if (size == length)
    {
      char * newstr = mozhegova::changeSize(str, length);
      str = newstr;
      length += 10;
    }
    str[size++] = next;
  }
  str[size] = '\0';
  std::skipws(in);
  return str;
}

char * mozhegova::changeSize(char * nowstr, size_t length)
{
  char * newstr = nullptr;
  try
  {
    newstr = new char [length + 10];
  }
  catch(const std::bad_alloc & e)
  {
    delete[] nowstr;
    throw;
  }
  for (size_t i = 0; i < length; i++)
  {
    newstr[i] = nowstr[i];
  }
  delete[] nowstr;
  return newstr;
}

char * mozhegova::spcRmv(char * str)
{
  size_t i = 0;
  size_t j = 0;
  while (str[i] != '\0')
  {
    if (!std::isspace(str[i]))
    {
      str[j++] = str[i];
    }
    else if (j > 0 && !std::isspace(str[j - 1]))
    {
      str[j++] = ' ';
    }
    i++;
  }
  if (j > 0 && std::isspace(str[j - 1]))
  {
    j--;
  }
  str[j] = '\0';
  return str;
}
