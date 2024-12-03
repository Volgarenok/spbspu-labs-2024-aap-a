#include "workWithString.hpp"

#include <cstdlib>
#include <exception>

char * guseynov::expandMassive(const char *arr, size_t &size, size_t step)
{
  char *newarr = reinterpret_cast< char* >(malloc(size + step + 1));
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
  size_t reserved = 100;
  size_t stringLength = 0;
  constexpr size_t step = 100;
  char *arr = reinterpret_cast< char* >(malloc(reserved));
  if (!arr)
  {
    return arr;
  }
  char c = '\0';
  constexpr char stop = '\n';
  std::noskipws(in);
  char *copyarr = nullptr;
  while ((in >> c) && (c != stop))
  {
    arr[stringLength++] = c;
    if (stringLength == reserved)
    {
      copyarr = expandMassive(arr, reserved, step);
      free(arr);
      arr = copyarr;
      reserved += step;
      if (!arr)
      {
        std::skipws(in);
        return nullptr;
      }
    }
  }
  std::skipws(in);
  copyarr = expandMassive(arr, stringLength, 0);
  free(arr);
  return copyarr;
}
