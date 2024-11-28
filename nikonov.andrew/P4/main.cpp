#include <iostream>
#include <cctype>
#include <cstddef>
#include <dynamicArray.hpp>
#include "formline.hpp"
int main()
{
  size_t capacity = 10;
  char* firstLine = nikonov::getLine(std::cin, capacity);
  if (!firstLine)
  {
    std::cerr << "ERROR: imposible to getLine\n";
    return 1;
  }
  char secondLine[] = "50ftw34r_3n8in33r1n8\0";
  firstLine = nikonov::reallocate(firstLine, capacity, 1, 10);
  if (!firstLine)
  {
    return 1;
  }
  nikonov::dgt_snd(firstLine, secondLine);
  std::cout << firstLine << '\n';
  free(firstLine);
}
