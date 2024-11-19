#include "workWithString.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

char * guseynov::getNewArr(char *arr, size_t size, size_t step)
{
  char *newarr = static_cast<char*>(malloc(size+step+1));

  for (size_t i = 0; i < size; i++)
  {
    newarr[i] = arr[i];
  }
  free(arr);
  newarr[size+step] = '\0';
  return newarr;
}

size_t guseynov::identifyUniqueChar(const char *inputString, const char *uniqueChars, size_t num)
{
  bool used[num] = {};
  for (size_t i = 0; i < num; i++)
  {
    used[i] = true;
  }
  size_t current = 0;
  size_t res = 0;
  while (inputString[current++] != '\0')
  {
    for (size_t j = 0; j < num; j++)
    {
      if ((used[j]) && (inputString[current] == uniqueChars[j]))
      {
        used[j] = false;
        res++;
      }
    }
  }
  return res;
}
