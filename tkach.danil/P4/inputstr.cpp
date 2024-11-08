#include "strfunc.h"
#include <iostream>
void tkach::inputStr(std::istream& in, char*& str, size_t& capacity)
{
  size_t i = 0;
  char symbol = '\0';
  in >> std::noskipws;
  while((in >> symbol) && (symbol != '\n'))
  {
    if (i+1 == capacity)
    {
      if (tkach::getMemoryForStr(str, capacity) == 1)
      {
        throw;
      }
    }
    str[i++] = symbol;
  }
}