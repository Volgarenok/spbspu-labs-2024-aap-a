#include "workWithString.hpp"

#include <stdlib.h>
#include <cstdlib>
#include <exception>

char * guseynov::expandMatrix(char *arr, size_t size, size_t step)
{
  char *newarr = nullptr;
  try
  {
    newarr = static_cast< char* >(malloc(sizeof(char)*(size + step)));
  }
  catch(std::bad_alloc & e)
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
  try
  {
    arr = static_cast< char* >(malloc(sizeof(char)*(reserved)));
  }
  catch(std::bad_alloc & e)
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
        temp = guseynov::expandMatrix(arr, reserved, step);
        free(arr);
        arr = guseynov::expandMatrix(temp, reserved, step);
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
    temp = guseynov::expandMatrix(arr, stringLength, 0);
    free(arr);
    arr = guseynov::expandMatrix(temp, stringLength, 0);
    free(temp);
  }
  catch(std::bad_alloc & e)
  {
    free(temp);
    free(arr);
    throw;
  }
  return arr;
}

size_t guseynov::determiningNumOfLetters(const char *inputString, size_t stringLength)
{
  size_t res = 0;
  size_t numUsed[26] = {};
  for (size_t i = 0; i < stringLength; i++)
  {
    if ((inputString[i] >= 'a') && (inputString[i] <= 'z'))
    {
      numUsed[inputString[i] - 'a']++;
    }
    else
    {
      if  ((inputString[i] >= 'A') && (inputString[i] <= 'Z'))
      {
        numUsed[inputString[i] - 'A']++;
      }
    }
  }
  for (size_t i = 0; i < 26; i++)
  {
    if (numUsed[i] != 0)
    {
      res++;
    }
  }
  return res;
}
