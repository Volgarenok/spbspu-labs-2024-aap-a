#include "string_conversion.h"
#include <cstdlib>
#include <cstddef>

char* finaev::creatureStr(size_t capacity)
{
  char* str = reinterpret_cast< char* >(malloc((capacity + 1) * sizeof(char)));
  return str;
}

char* finaev::fillStr(std::istream& in)
{
  size_t capacity = 10;
  char* str = finaev::creatureStr(capacity);
  if (str == nullptr)
  {
    return nullptr;
  }
  size_t length = 0;
  char c = '\0';
  std::noskipws(in);
  while ((in >> c) && (c != '\n'))
  {
    if (length == capacity)
    {
      capacity *= 2;
      char* new_str = finaev::creatureStr(capacity);
      if (new_str == nullptr)
      {
        free(str);
        return nullptr;
      }
      transferStr(new_str, str, length);
      free(str);
      str = new_str;
    }
    str[length++] = c;
  }
  str[length] = '\0';
  std::skipws(in);
  return str;
}
