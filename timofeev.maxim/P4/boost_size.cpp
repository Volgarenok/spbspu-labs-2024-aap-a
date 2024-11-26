#include "functions.h"
#include <iostream>

char* timofeev::boost_size(char* value_line, size_t capacity)
{
  char* new_line = reinterpret_cast< char* >(malloc(sizeof(char) * (capacity)));
  if (new_line == nullptr)
  {
    free(new_line);
    return nullptr;
  }
  for (size_t i = 0; value_line[i] != '\0'; i++)
  {
    new_line[i] = value_line[i];
  }
  free(new_line);
  return new_line;
}
