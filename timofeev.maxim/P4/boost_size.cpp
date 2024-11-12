#include "functions.h"
#include <iostream>

char* timofeev::boost_size(char* value_line, size_t capacity)
{
  int new_capacity = capacity + 10;
  char* new_line = reinterpret_cast<char*>(malloc(sizeof(char) * (new_capacity+1)));
  for (size_t i = 0; i < capacity; i++)
  {
    new_line[i] = value_line[i];
  }
  new_line[new_capacity] = '\0';
  free(value_line);
  return new_line;
}
