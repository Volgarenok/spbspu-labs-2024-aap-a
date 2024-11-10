#include "strfunc.h"

std::istream& tkach::inputStr(std::istream& in, char*& str, size_t& capacity)
{
  size_t i = 0;
  char symbol = '\0';
  in >> std::noskipws;
  while(in >> symbol)
  {
    if (i + 1 == capacity)
    {
      str[i] = '\0';
      if (tkach::getMemoryForStr(str, capacity) == 1)
      {
        throw;
      }
    }
    str[i++] = symbol;
  }
  str[i] = '\0';
  return in;
}
