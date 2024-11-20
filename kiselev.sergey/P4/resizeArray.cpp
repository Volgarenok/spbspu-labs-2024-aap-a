#include "resizeArray.h"
#include <cstdlib>
char* kiselev::resizeArr(char* array, size_t length, size_t length2)
{
  char* arr2 = static_cast<char*>(malloc(length * sizeof(char)));
  if (arr2 == nullptr)
  {
    return nullptr;
  }
  for (size_t i = 0; i < length2; ++i)
  {
    arr2[i] = array[i];
  }
  return arr2;
}
