#include "arrays_reading.hpp"

int kushekbaev::hasCommonChars(const char* str1, size_t size1, const char* str2, size_t size2)
{
  for (size_t i = 0; i < size1; i++)
  {
    for (size_t j = 0; j < size2; j++)
    {
      if (str1[i] == str2[j])
      {
        return 1;
      }
    }
  }
  return 0;
}
