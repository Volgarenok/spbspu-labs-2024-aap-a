#include "inputString.hpp"
#include <iostream>
#include <cstddef>
#include "resize.hpp"

char* asafov::inputString(std::istream& in)
{
  size_t reallength = 0;
  size_t possiblelength = 1;
  char* string = new char[possiblelength];
  char ch = 0;
  while (!in.eof())
  {
    possiblelength--;
    in >> ch;
    if (in.fail() || in.eof())
    {
      string[reallength] = '\0';
      break;
    }
    string[reallength] = ch;
    reallength++;
    if (possiblelength == 0)
    {
      possiblelength = reallength;
      char* newstring = nullptr;
      try
      {
        newstring = resize(string, reallength, reallength * 2);
      }
      catch (const std::bad_alloc&)
      {
        delete[] string;
        throw;
      }
      delete[] string;
      string = newstring;
    }
  }
  if (reallength == 0)
  {
    string[0] = 0;
  }
  return string;
}
