#include "workWithString.hpp"

#include <stdio.h>
#include <stdlib.h>

char * guseyn::inputLine(std::istream & in, char stop)
{
  char *arr = nullptr;
  char *arrcopy = nullptr;
  char c = '\0';
  size_t min = 10;
  size_t size = 0;
  arr = static_cast < char* > (malloc(min));
  arrcopy = static_cast < char* > (malloc(min));
  if ((arr == NULL) || (arrcopy == NULL))
  {
    exit(1);
  }
  std::noskipws(in);
  while ((c != stop) && (in >> c))
  {
    arr[size++] = c;
    if (size == min)
    {
      min += 10;
      arrcopy = arr;
      arr = static_cast < char* > (malloc(min));
      arr = arrcopy;
      arrcopy = static_cast < char* > (malloc(min));
    }
  }
  arrcopy = arr;
  arr = static_cast < char* > (malloc(size++));
  arr = arrcopy;
  arr[size] = '\n';
  return arr;
}

size_t guseyn::identifyUniqueChar(char *inputString, char *uniqueChars, size_t num)
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
