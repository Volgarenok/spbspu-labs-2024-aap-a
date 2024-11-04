#include "intcheck.hpp"
#include <iostream>
#include <string>

int brevnov::intcheck(char * input)
{
  bool convertible = true;
  size_t i = 0;
  while (input[i] != 0)
  {
    if (!std::isdigit(input[i]))
    {
      convertible = false;
      break;
    }
    ++i;
  }
  if (convertible)
  {
    return std::atoi(input);
  }
  else
  {
    throw std::invalid_argument("Incorrect input");
  }
}