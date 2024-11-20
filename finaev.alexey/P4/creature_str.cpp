#include "string_conversion.h"
#include <cstdlib>
#include <cstddef>

char* finaev::creature_empty_str(size_t dl)
{
  char* str = reinterpret_cast< char* >(malloc((dl + 1) * sizeof(char)));
  str[dl] = '\0';
  return str;
}

char* finaev::fill_str(std::istream& in, char* str)
{
  size_t dl = 10;
  size_t tk_dl = 0;
  char c;
  std::noskipws(in);
  while ((in >> c) && (c != '\n'))
  {
    if (tk_dl == dl)
    {
      dl = dl * 2;
      char* new_str = nullptr;
      new_str = finaev::creature_empty_str(dl);
      if (new_str == nullptr)
      {
        free(str);
        return nullptr;
      }
      MEMcpy(new_str, str, tk_dl);
      free(str);
      str = new_str;
    }
    str[tk_dl] = c;
    tk_dl++;
  }
  if (tk_dl == 0)
  {
    free(str);
    return nullptr;
  }
  str[tk_dl] = '\0';
  return str;
}
