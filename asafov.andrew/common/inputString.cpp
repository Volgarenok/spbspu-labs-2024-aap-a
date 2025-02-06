#include "inputString.hpp"
#include <iostream>
#include <cstddef>
#include "resize.hpp"

char* asafov::inputString()
{
  size_t length = 0;
  size_t count = 1;
  char* string = new char[count];
  char ch = 0;
  while (!std::cin.eof())
  {
    count--;
    std::cin >> ch;
    if(std::cin.fail() || std::cin.eof())
    {
      string[length] = '\0';
      break;
    }
    string[length] = ch;
    length++;
    if (count == 0)
    {
      count = length;
      char* newstring = nullptr;
      try
      {
        newstring = resize(string, length, length);
      }
      catch (const std::bad_alloc& e)
      {
        delete[] string;
        throw e;
      }
      delete[] string;
      string = newstring;
    }
  }
  if (length == 0)
  {
    string[0] = 0;
  }
  return string;
}
