#include "string.h"
#include <iostream>
char* alymova::increase(char* str, size_t size)
{
  char* str_new = reinterpret_cast< char* >(malloc((size + 1) * sizeof(char)));
  if (str_new == nullptr)
  {
    throw std::overflow_error("Error: memory not allocate for string");
  }
  str_new[size] = '\0';
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    str_new[i] = str[i];
  }
  str = reinterpret_cast< char* >(malloc((size + 1) * sizeof(char)));
  if (str == nullptr)
  {
    throw std::overflow_error("Error: memory not allocate for string");
  }
  str[size] = '\0';
  for (size_t i = 0; str_new[i] != '\0'; i++)
  {
    str[i] = str_new[i];
  }
  free(str_new);
  return str;
}
