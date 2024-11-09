#include <iostream>
#include <cctype>
#include <cstddef>
#include "lineinput.hpp"
#include "lineoutput.hpp"
#include "formline.hpp"
int main()
{
  size_t capacity = 10;
  char* firstLine = getLine(capacity);
  if (!firstLine)
  {
    std::noskipws(std::cin);
    std::cerr << "ERROR: imposible to getLine\n";
    return 1;
  }
  char secondLine[] = "aF1 df145\0";
  firstLine = reallocate(firstLine, capacity, cntDgt(firstLine));
  if (!firstLine)
  {
    std::cerr << "ERROR: bad alloc\n";
    return 1;
  }
  add_digit_symb(firstLine, secondLine);
  printLine(firstLine);
}
