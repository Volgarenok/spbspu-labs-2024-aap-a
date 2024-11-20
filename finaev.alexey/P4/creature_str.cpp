#include "string_conversion.h"
#include <cstdlib>
#include <cstddef>

char* finaev::creature_empty_str(size_t dl)
{
  char* str = reinterpret_cast< char* >(malloc((dl + 1) * sizeof(char)));
  str[dl] = '\0';
  return str;
}

char* finaev::fill_str(std::istream& in)
{
  size_t dl = 10;
  char* str = finaev::creature_empty_str(dl);
  if (str == nullptr)
  {
    return nullptr;
  }
  size_t tk_dl = 0;
  char c = '\0';
  std::noskipws(in);
  while ((in >> c) && (c != '\n'))
  {
    if (tk_dl == dl)
    {
      char* new_str = finaev::creature_empty_str(dl * 2);
      if (new_str == nullptr)
      {
        free(str);
        return nullptr;
      }
      finaev::MEMcpy(new_str, str);
      str = new_str;
      free(new_str);
      dl *= 2;
    }
    str[tk_dl++] = c;
  }
  if (tk_dl == 0)
  {
    free(str);
    return nullptr;
  }
  return str;
}
