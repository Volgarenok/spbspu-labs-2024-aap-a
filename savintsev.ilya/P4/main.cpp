#include "dynamicstrings.h"
#include <iostream>

int main()
{
  char * line = nullptr;
  line = savintsev::inputEndlessString(std::cin, '\0');
  std::cout << savintsev::getNumIdenticalInRow(line) << '\n';
  delete[] line;
}
