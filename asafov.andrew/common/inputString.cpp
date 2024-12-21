#include "inputString.hpp"
#include <iostream>
#include <cstddef>
#include "resize.hpp"

char* asafov::inputString()
{
  size_t length = 0;
  size_t count = 8;
  char* string = new char[count];
  for(size_t i = 0; i < 8; i++)
  {
    string[i] = '\0';
  }
  char ch = 0;
  while (true)
  {
    count--;
    std::cin >> ch;
    if(std::cin.fail() || std::cin.eof())
    {
      break;
    }
    string[length] = ch;
    length++;
    if (count == 0)
    {
      count = 8;
      string = asafov::resize(string, length);
    }
  }
  return string;
}
