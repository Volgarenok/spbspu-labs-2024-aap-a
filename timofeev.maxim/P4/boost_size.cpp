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
  return new_line;
}
