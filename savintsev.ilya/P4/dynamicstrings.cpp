#include "dynamicstrings.h"
#include <cstddef>

size_t savintsev::getNumIdenticalInRow(const char * c)
{
  if (c == nullptr)
  {
    return 0;
  }
  size_t k = 0;
  for (size_t i = 0; c[i] != '\0'; ++i)
  {
    if (c[i] == c[i + 1])
    {
      ++k;
    }
  }
  return k;
}
