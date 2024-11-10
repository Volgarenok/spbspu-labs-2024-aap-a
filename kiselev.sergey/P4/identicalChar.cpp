#include "identicalChar.h"
#include <cstddef>
size_t kiselev::identicalChar(char* arr1, const char* arr2)
{
  if (arr1 == nullptr || arr2 == nullptr)
  {
    return 0;
  }
  size_t quantity = 0;
  for (size_t i = 0; arr2[i] != '\0'; ++i)
  {
    for (size_t j = 0; arr1[j] != '\0'; ++j)
    {
      if (arr1[j] == arr2[i])
      {
        quantity++;
      }
    }
  }
  return quantity;
}

