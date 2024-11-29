#include "workWithString.hpp"

#include <cstdlib>
#include <exception>

void guseynov::expandMassive(char *arr, size_t & size, size_t step)
{
  char *newarr = reinterpret_cast< char* >(malloc(sizeof(char)*(size + step)));
  if (newarr != nullptr)
  {
    for (size_t i = 0; i < size; i++)
    {
      newarr[i] = arr[i];
    }
    free(arr);
    arr = reinterpret_cast< char* >(malloc(sizeof(char)*(size + step + 1)));
    if (arr != nullptr)
    {
      for (size_t i = 0; i < size; i++)
      {
      arr[i] = newarr[i];
      }
      size += step;
      arr[size] = '\0';
    }
    free(newarr);
  }
}

char * guseynov::getLine(std::istream & in)
{
  char *arr = nullptr;
  size_t reserved = 10;
  size_t stringLength = 0;
  constexpr size_t step = 10;
  arr = reinterpret_cast< char* >(malloc(sizeof(char)*(reserved)));
  if (arr == nullptr)
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
      guseynov::expandMassive(arr, reserved, step);
      if (reserved == stringLength)
      {
        free(arr);
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
  guseynov::expandMassive(arr, stringLength, 0);
  return arr;
}

