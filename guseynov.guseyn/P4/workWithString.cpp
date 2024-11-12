#include "workWithString.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

char * guseyn::newarr(char *arr, size_t size)
{
  char *newarr = static_cast < char* > (malloc(size+1));

  for (size_t i = 0; arr[i] != '\0'; i++)
  {
    newarr[i] = arr[i];
  }
  free(arr);
  newarr[size] = '\0';
  return newarr;
}

size_t guseyn::identifyUniqueChar(const char *inputString, const char *uniqueChars, size_t num)
{
  bool *check;
  size_t res = 0;
  size_t current = 0;
  check = reinterpret_cast < bool* > (malloc((num) * sizeof(bool)));
  for (size_t i = 0; i < num; i++)
  {
    check[i] = true;
  }
  while (inputString[current++] != '\0')
  {
    for (size_t j = 0; j < num; j++)
    {
      if ((check[j]) && (inputString[current] == uniqueChars[j]))
      {
        check[j] = false;
        res++;
      }
    }
  }
  free(check);
  return res;
}
