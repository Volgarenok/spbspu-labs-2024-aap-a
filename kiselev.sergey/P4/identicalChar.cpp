#include "identicalChar.h"
int kiselev::identicalChar(char* arr1, const char* arr2, size_t lenght1, size_t lenght2)
{
  int quantity = 0;
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

