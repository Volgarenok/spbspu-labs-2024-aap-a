#include "workWithString.hpp"

#include <stdlib.h>
#include <cstdlib>
#include <exception>
#include <cctype>

char * guseynov::expandMassive(char *arr, size_t size, size_t step)
{
  char *newarr = nullptr;
  newarr = static_cast< char* >(malloc(sizeof(char)*(size + step)));
  if (newarr == nullptr)
  {
    throw;
  }
  for (size_t i = 0; i < size; i++)
  {
    newarr[i] = arr[i];
  }
  return newarr;
}

char * guseynov::getLine(std::istream & in, size_t & stringLength)
{
  char *temp = nullptr;
  char *arr = nullptr;
  size_t reserved = 10;
  constexpr size_t step = 10;
  arr = static_cast< char* >(malloc(sizeof(char)*(reserved)));
  if (arr == nullptr)
  {
    throw;
  }
  char c = '\0';
  constexpr char stop = '\n';
  std::noskipws(in);
  while ((in >> c) && (c != stop))
  {
    arr[stringLength++] = c;
    if (stringLength == reserved)
    {
      try
      {
        temp = guseynov::expandMassive(arr, reserved, step);
        free(arr);
        arr = guseynov::expandMassive(temp, reserved, step);
        free(temp);
      }
      catch(std::bad_alloc & e)
      {
        free(arr);
        free(temp);
        throw;
      }
      reserved += step;
    }
  }
  std::skipws(in);
  if (!in)
  {
    free(arr);
    return nullptr;
  }
  try
  {
    temp = guseynov::expandMassive(arr, stringLength, 0);
    free(arr);
    arr = guseynov::expandMassive(temp, stringLength, 0);
    free(temp);
  }
  catch(std::bad_alloc & e)
  {
    free(arr);
    free(temp);
    throw;
  }
  return arr;
}

size_t guseynov::determiningNumOfLetters(const char *inputString, size_t stringLength)
{
  size_t res = 0;
  size_t f = 0;
  for (size_t i = 0; i < stringLength; i++)
  {
    if (isalpha(inputString[i]))
    {
      for (size_t j = 0; j < i; j++)
      {
        if (inputString[j] == inputString[i])
        {
          f = 1;
        }
      }
      if (f != 0)
      {
        f = 0;
      }
      else
      {
        res++;
      }
    }
  }
  return res;
}
