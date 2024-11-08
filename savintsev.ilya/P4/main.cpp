#include "dynamicstrings.h"
#include <iostream>

int main()
{
  char * line = nullptr;
  line = savintsev::inputEndlessStr(std::cin);
  if (line == nullptr)
  {
    std::cerr << "Failure to allocate memory\n";
    return 1;
  }
  int k = savintsev::getNumIdenticalInRow(line);
  if (k == -1)
  {
    std::cerr << "No characters to convert\n";
    return 1;
  }
  std::cout << k << '\n';
  delete[] line;
}
