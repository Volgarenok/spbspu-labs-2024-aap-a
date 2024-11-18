#include "string_conversion.h"
#include <cstdlib>
#include <cstddef>

char* finaev::creature_str(size_t dl)
{
  char* str = reinterpret_cast< char* >(malloc((dl + 1) * sizeof(char)));
  str[dl] = '\0';
  return str;
}
