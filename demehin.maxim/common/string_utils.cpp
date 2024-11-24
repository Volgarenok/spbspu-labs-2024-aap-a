#include "string_utils.h"
#include <stdexcept>

char* demehin::copyString(char* str, size_t size)
{
  size_t temp_size = 0;
  char* new_str = new char[size];
  if (!new_str)
  {
    throw std::bad_alloc();
  }

  while (str[temp_size] != '\0')
  {
    new_str[temp_size] = str[temp_size];
    temp_size += 1;
  }
  delete[] str;
  return new_str;
}


char* demehin::getString(std::istream& in, char stop, size_t max_size)
{
  char* str = nullptr;
  str = new char[max_size];
  str[0] = '\0';
  size_t size = 0;
  char temp = '\0';
  std::noskipws(in);
  while ((in >> temp) && (temp != stop))
  {
    if (size + 1 == max_size)
    {
      str[max_size - 1] = '\0';
      max_size *= 2;
      str = copyString(str, max_size);
    }
    str[size++] = temp;
  }
  str[size] = '\0';
  return str;
}
