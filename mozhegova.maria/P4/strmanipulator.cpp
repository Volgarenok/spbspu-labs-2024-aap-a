#include "strmanipulator.hpp"
#include <cctype>

char * mozhegova::inputString(std::istream & in, char stop)
{
  size_t length = 10;
  char * str = new char [length + 1];
  size_t size = 0;
  char next = '\0';
  std::noskipws(in);
  while ((in >> next) && (next != stop))
  {
    if (size == length)
    {
      char * newstr = nullptr;
      try
      {
        newstr = mozhegova::changeSize(str, length);
      }
      catch (const std::bad_alloc & e)
      {
        delete[] str;
        throw;
      }
      delete[] str;
      str = newstr;
      length += 10;
    }
    str[size++] = next;
  }
  str[size] = '\0';
  std::skipws(in);
  return str;
}

char * mozhegova::changeSize(const char * currentstr, size_t length)
{
  char * newstr = new char [length + 10];
  for (size_t i = 0; i < length; i++)
  {
    newstr[i] = currentstr[i];
  }
  return newstr;
}

char * mozhegova::spcRmv(char * str)
{
  char * orig = str;
  char * res = str;
  bool lastWasSpace = false;
  while (*str)
  {
    if (!std::isspace(*str))
    {
      *res++ = *str;
      lastWasSpace = false;
    }
    else if (res != orig && !lastWasSpace)
    {
      *res++ = ' ';
      lastWasSpace = true;
    }
    str++;
  }
  if (lastWasSpace && res != orig)
  {
    res--;
  }
  *res = '\0';
  return orig;
}
