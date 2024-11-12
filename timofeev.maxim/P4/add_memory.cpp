#include "functions.h"

char* timofeev::add_memory(size_t capacity)
{
  char* memory = reinterpret_cast<char*>(malloc(sizeof(char) * capacity));
  return memory;
}
