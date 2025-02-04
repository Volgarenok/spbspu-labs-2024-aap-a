#include "inputString.hpp"
#include <iostream>
#include <cstddef>
#include "resize.hpp"

#define INCREASE 8

char* asafov::inputString()
{
  size_t length = 0;
  size_t count = INCREASE;
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
      count = INCREASE;
      string = resize(string, length, INCREASE);
    }
  }
  if (length == 0)
  {
    string[0] = 0;
  }
  return string;
}
