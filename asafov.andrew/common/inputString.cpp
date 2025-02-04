#include "inputString.hpp"
#include <iostream>
#include <cstddef>
#include "resize.hpp"

char* asafov::inputString()
{
  size_t length = 0;
  size_t count = 8;
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
      count = 8;
      string = resize(string, length);
    }
  }
  if (length == 0)
  {
    string[0] = 0;
  }
  return string;
}
