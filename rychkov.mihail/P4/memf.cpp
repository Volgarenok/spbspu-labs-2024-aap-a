#include "memf.hpp"

#include <cstdlib>

char* rychkov::realloc(char* arr, size_t oldLen, size_t newLen)
{
  char* result = reinterpret_cast< char* >(malloc(newLen * sizeof(char)));
  if (!result || !arr)
  {
    return result;
  }

  size_t copyLen = (newLen > oldLen ? oldLen : newLen);
  for (size_t i = 0; i < copyLen; i++)
  {
    result[i] = arr[i];
  }
  free(arr);
  return result;
}
