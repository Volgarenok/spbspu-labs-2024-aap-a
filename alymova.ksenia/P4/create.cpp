#include "dynamic_string.h"
#include <cstdlib>
#include <stdexcept>
#include <cstddef>
char* alymova::create(size_t size)
{
  char* str = reinterpret_cast< char* >(malloc((size + 1) * sizeof(char)));
  str[size] = '\0';
  return str;
}
