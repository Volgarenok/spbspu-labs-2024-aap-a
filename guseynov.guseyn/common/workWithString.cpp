#include "workWithString.hpp"

#include <cstdlib>
#include <exception>

char * guseynov::expandMassive(char *arr, size_t & size, size_t step)
{
  char *newarr = reinterpret_cast< char* >(malloc(sizeof(char)*(size + step + 1)));
  if (newarr != nullptr)
  {
    for (size_t i = 0; i < size; i++)
    {
      newarr[i] = arr[i];
    }
    newarr[size + step] = '\0';
  }
  return newarr;
}

char * guseynov::getLine(std::istream & in)
{
  size_t reserved = 10;
  size_t stringLength = 0;
  constexpr size_t step = 10;
  char *arr = reinterpret_cast< char* >(malloc(sizeof(char)*(reserved)));
  if (!arr)
  {
    return arr;
  }
  char c = '\0';
  constexpr char stop = '\n';
  std::noskipws(in);
  while ((in >> c) && (c != stop))
  {
    arr[stringLength++] = c;
    if (stringLength == reserved)
    {
      arr = expandMassive(arr, reserved, step);
      reserved += step;
      if (!arr)
      {
        std::skipws(in);
        return nullptr;
      }
    }
  }
  std::skipws(in);
  if (!in)
  {
    free(arr);
    return nullptr;
  }
  arr = expandMassive(arr, stringLength, 0);
  return arr;
}

