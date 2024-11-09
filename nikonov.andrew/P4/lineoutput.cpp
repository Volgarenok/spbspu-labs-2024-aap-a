#include "lineoutput.hpp"
#include <iostream>
void printLine(char* line)
{
  size_t iter = 0;
  while (line[iter] != '\0')
  {
    std::cout << line[iter];
    ++iter;
  }
  std::cout << "\n";
}
