#include "making_new_cstring.hpp"
#include <iostream>

void petrov::outputNewCString(char * new_cstring)
{
  size_t i = 0;
  while (new_cstring[i] != '\0')
  {
    std::cout << new_cstring[i];
    i++;
  }
  std::cout << "\n";
}
