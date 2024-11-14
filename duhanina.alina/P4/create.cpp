#include "functionStr.h"
#include <cstddef>

char* duhanina::createNewArray(char* array, char* new_array)
{
  size_t i = 0;
  for (i = 0; array[i] != '\0'; ++i)
  {
    new_array[i] = array[i];
  }
  new_array[i] = '\0';
  delete[] array;
  return new_array;
}
