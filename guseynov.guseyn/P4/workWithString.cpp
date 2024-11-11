#include "workWithString.hpp"

#include <stdio.h>
#include <stdlib.h>

void guseyn::copyarr(const char *arr, char *arrcopy, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    arrcopy[i] = arr[i];
  }
}

char * guseyn::inputLine(std::istream & in, char stop)
{
  char *arr = nullptr;
  char *arrcopy = nullptr;
  char c = '\0';
  size_t min = 10;
  size_t size = 0;
  arr = static_cast < char* > (malloc(min));
  arrcopy = static_cast < char* > (malloc(min));
  std::noskipws(in);
  while ((c != stop) && (in >> c))
  {
    arr[size++] = c;
    if (size == min)
    {
      min += 10;
      guseyn::copyarr(arr, arrcopy, size);
      arr = static_cast < char* > (malloc(min));
      guseyn::copyarr(arrcopy, arr, size);
      arrcopy = static_cast < char* > (malloc(min));
    }
  }
  guseyn::copyarr(arr, arrcopy, size);
  arr = static_cast < char* > (malloc(size++));
  guseyn::copyarr(arrcopy, arr, (size-1));
  arr[size] = '\n';
  free(arrcopy);
  return arr;
}

size_t guseyn::identifyUniqueChar(const char *inputString, const char *uniqueChars, size_t num)
{
  bool *check;
  size_t res = 0;
  size_t current = 0;
  check = reinterpret_cast< bool* > (malloc(num));
  for (size_t i = 0; i < num; i++)
  {
    check[i] = true;
  }
  while (inputString[current++] != '\n')
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
