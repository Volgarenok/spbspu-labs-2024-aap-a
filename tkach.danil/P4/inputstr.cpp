#include "strfunc.h"

char* tkach::inputStr(std::istream& in, char* str, size_t& capacity)
{
  size_t str_length = 0;
  char symbol = '\0';
  in >> std::noskipws;
  while(in >> symbol && symbol != '\n')
  {
    if (str_length + 1 == capacity)
    {
      str[str_length] = '\0';
      str = tkach::getMemoryForStr(str, capacity);
      if (str == nullptr)
      {
        return nullptr;
      }
    }
    str[str_length++] = symbol;
  }
  str[str_length] = '\0';
  return str;
}
