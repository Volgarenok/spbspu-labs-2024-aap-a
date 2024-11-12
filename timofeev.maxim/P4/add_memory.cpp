#include "functions.h"

char* add_memory(size_t capacity)
{
  memory = reinterpret_cast<char*>(malloc(sizeof(char) * new_capacity));
  return memory;
}
