#include <iostream>
#include <cctype>
#include <cstddef>
#include "lineinput.hpp"
#include "lineoutput.hpp"
#include "formline.hpp"
int main()
{
  size_t capacity = 10;
  char* firstLine = nikonov::getLine(capacity);
  if (!firstLine)
  {
    std::noskipws(std::cin);
    std::cerr << "ERROR: imposible to getLine\n";
    return 1;
  }
  char secondLine[] = "50ftw3ar_3n8in33r1n8\0";
  firstLine = nikonov::reallocate(firstLine, capacity, nikonov::cntDgt(firstLine));
  if (!firstLine)
  {
    std::cerr << "ERROR: bad alloc\n";
    return 1;
  }
  nikonov::add_digit_symb(firstLine, secondLine);
  nikonov::printLine(firstLine);
  free(firstLine);
}
