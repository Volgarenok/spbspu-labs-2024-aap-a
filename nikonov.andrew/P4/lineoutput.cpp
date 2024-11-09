#include "lineoutput.hpp"
#include <iostream>
void printLine(char* line)
{
  size_t iter = 0;
  while (line[iter] != '\n')
  {
    std::cout << line[iter];
  }
}
