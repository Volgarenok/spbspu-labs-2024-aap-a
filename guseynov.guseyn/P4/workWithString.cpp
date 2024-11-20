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

char * guseynov::getLine(std::istream & in, char stop)
{
  char *arr = nullptr;
  size_t reserved = 10;
  constexpr size_t step = 10;
  size_t wPoint = 0;
  arr = static_cast<char*>(malloc(reserved));
  char c = '\0';
  std::noskipws(in);
  while ((in >> c) && (c != stop))
  {
    arr[wPoint++] = c;
    if (wPoint == reserved)
    {
      arr = guseynov::getNewArr(arr, reserved, step);
      reserved += step;
    }
  }
  if (!in)
  {
    free(arr);
    return nullptr;
  }
  arr = guseynov::getNewArr(arr, wPoint, 0);
  return arr;
}

size_t guseynov::identifyUniqueChar(const char *inputString)
{
  bool used[26] = {false};
  size_t current = 0;
  size_t res = 0;
  while (inputString[current++] != '\0')
  {
    if ((inputString[current] >= 'a') && (inputString[current] <= 'z') && (!used[inputString[current] - 'a']))
    {
      used[inputString[current] - 'a'] = true;
      res++;
    }
  }
  return res;
}
