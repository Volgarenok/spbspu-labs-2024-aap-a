#include "functionStr.h"
#include <cstddef>

char* duhanina::createNewArray(char* array, char* new_array)
{
  for (size_t i = 0; array[i] != '\0'; ++i)
  {
    new_array[i] = array[i];
  }
  delete[] array;
  return new_array;
}
