#include "strfunc.h"

char* tkach::inputStr(std::istream& in, char* str, size_t& capacity)
{
  size_t i = 0;
  char symbol = '\0';
  in >> std::noskipws;
  while(in >> symbol && symbol != '\n')
  {
    if (i + 1 == capacity)
    {
      str[i] = '\0';
      try
      {
        str = tkach::getMemoryForStr(str, capacity);
      }
      catch (const std::bad_alloc& e)
      {
        throw;
      }
    }
    str[i++] = symbol;
  }
  str[i] = '\0';
  return str;
}
