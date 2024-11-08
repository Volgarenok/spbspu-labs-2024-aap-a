#include "string.h"

char* demehin::copyString(char* str, size_t size)
{
  size_t temp_size = 0;
  char* new_str = nullptr;
  try
  {
    new_str = new char[size];
  }
  catch (std::bad_alloc& e)
  {
    throw;
  }

  while (str[temp_size] != '\0')
  {
    new_str[temp_size] = str[temp_size];
    temp_size += 1;
  }
  delete [] str;
  return new_str;
}

char* (char* str, char* base_str)
{
  size_t i = 0;
}
