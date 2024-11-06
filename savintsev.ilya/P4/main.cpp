#include "dynamicstrings.h"
#include <iostream>

int main()
{
  char * line = nullptr;
  line = savintsev::inputEndlessString(std::cin, '\n');
  std::cout << savintsev::getNumIdenticalInRow(line) << '\n';
  delete[] line;
}
