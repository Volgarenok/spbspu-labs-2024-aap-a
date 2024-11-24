#include "dynamic_string.h"
#include <istream>
#include <cstddef>
#include <cstdlib>
char* alymova::copy_string(const char* str, size_t end, char* str_new)
{
  char* ptr_new = str_new;
  const char* ptr = str;
  for (; ptr != (str + end); ptr++)
  {
    *ptr_new = *ptr;
    ptr_new++;
  }
  return str_new;
}
char* alymova::get_string(std::istream& in, size_t& capacity, size_t& size, int ratio, char delim)
{
  if (capacity == 0 || size >= capacity || ratio <= 1)
  {
    return nullptr;
  }
  char* str = reinterpret_cast< char* >(malloc((capacity + 1) * sizeof(char)));
  if (str == nullptr)
  {
    return nullptr;
  }
  str[capacity] = '\0';
  char next = '\0';
  in >> std::noskipws;
  while ((in >> next) && (next != delim))
  {
    str[size] = next;
    size += 1;
    if (size == capacity)
    {
      capacity *= ratio;
      char* str_new = reinterpret_cast< char* >(malloc((capacity + 1) * sizeof(char)));
      if (str_new == nullptr)
      {
        capacity = size;
        free(str);
        return nullptr;
      }
      str_new[capacity] = '\0';
      str_new = copy_string(str, size, str_new);
      free(str);
      str = str_new;
    }
  }
  str[size] = '\0';
  in >> std::skipws;
  return str;
}
