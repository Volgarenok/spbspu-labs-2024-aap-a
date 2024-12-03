#include <iostream>
#include "inputString.hpp"
#include "resize.hpp"

char* asafov::inputString(unsigned long long& lenght)
{
  unsigned long long count = 8;
  char* a = new char[count];
  char g = 0;
  while (!std::cin.eof())
  {
    count--;
    std::cin >> g;
    if(std::cin.fail() || std::cin.eof())
    {
      break;
    }
    a[lenght] = g;
    lenght++;
    if (count == 0)
    {
      count = 8;
      a = asafov::resize(a, lenght);
    }
  }
  return a;
}
