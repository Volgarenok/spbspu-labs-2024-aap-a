#include "lineoutput.hpp"
#include <iostream>
void nikonov::printLine(const char* line)
{
  size_t iter = 0;
  while (line[iter] != '\0')
  {
    std::cout << line[iter];
    ++iter;
  }
  std::cout << "\n";
}
