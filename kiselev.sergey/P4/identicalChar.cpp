#include "identicalChar.h"
#include <cstddef>
size_t kiselev::identicalChar(char* arr1, const char* arr2, size_t lenght1, size_t lenght2)
{
  if (arr1 == nullptr || arr2 == nullptr)
  {
    return 0;
  }
  size_t quantity = 0;
  for (size_t i = 0; i < lenght2; ++i)
  {
    for (size_t j = 0; j < lenght1; ++j)
    {
      if (arr1[j] == arr2[i])
      {
        quantity++;
      }
    }
  }
  return quantity;
}

