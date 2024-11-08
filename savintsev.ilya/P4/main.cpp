#include "dynamicstrings.h"
#include <iostream>

int main()
{
  char * line = nullptr;
  line = savintsev::inputEndlessString(std::cin);
  if (line == nullptr)
  {
    return 1;
  }
  std::cout << savintsev::getNumIdenticalInRow(line) << '\n';
  delete[] line;
}
