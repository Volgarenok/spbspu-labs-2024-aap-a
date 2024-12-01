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
  char* extended_firstLine = nikonov::reallocate(firstLine, capacity, 1, 10);
  if (!extended_firstLine)
  {
    free(firstLine);
    return 1;
  }
  nikonov::dgt_snd(extended_firstLine, secondLine);
  std::cout << extended_firstLine << '\n';
  free(extended_firstLine);
}
