#include "strfunc.h"
#include <iostream>

void tkach::outputStr(char* str)
{
  for(size_t i = 0; str[i] != '\0'; ++i)
  {
    std::cout << str[i];
    if (str[i + 1] == '\0' && str[i] != '\n')
    {
      std::cout << "\n";
    }
  }
}
