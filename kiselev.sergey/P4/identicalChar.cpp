#include "identicalChar.h"
#include <cstddef>
size_t kiselev::identicalChar(const char* arr1, const char* arr2)
{
  if (arr1 == nullptr || arr2 == nullptr)
  {
    return 0;
  }
  size_t quantity = 0;
  while (*arr2 != '\0')
  {
    while (*arr1 != '\0')
    {
      if (*arr1 == *arr2)
      {
        quantity++;
      }
      arr1++;
    }
    arr2++;
  }
  return quantity;
}

