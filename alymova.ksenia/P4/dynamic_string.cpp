#include "dynamic_string.h"
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <cstdlib>
char* alymova::copy_string(const char* str, size_t end, char* str_new)
{
  char* ptr_new = str_new;
  const char* ptr = str;
  for (; ptr != (str + end); ptr++)
  {
    *ptr_new = *ptr;
    ptr_new += 1;
  }
  return str_new;
}
char* alymova::upper_string(const char* str, size_t end, char* str_res)
{
  char* ptr_res = str_res;
  const char* ptr = str;
  for (; ptr != (str + end); ptr++)
  {
    if (std::islower(*ptr))
    {
      *ptr_res = static_cast< char >(std::toupper(*ptr));
    }
    else
    {
      *ptr_res = *ptr;
    }
    ptr_res += 1;
  }
  return str_res;
}
char* alymova::get_string(size_t& size, size_t& size_now, int ratio, char delim)
{
  char* str = reinterpret_cast< char* >(malloc((size + 1) * sizeof(char)));
  if (str == nullptr)
  {
    return nullptr;
  }
  str[size] = '\0';
  char next = '\0';
  while ((std::cin >> next) && (next != delim))
  {
    str[size_now] = next;
    size_now += 1;
    if (size_now == size)
    {
      size *= ratio;
      char* str_new = reinterpret_cast< char* >(malloc((size + 1) * sizeof(char)));
      if (str_new == nullptr)
      {
        free(str);
        return nullptr;
      }
      str_new[size] = '\0';
      str_new = alymova::copy_string(str, size / ratio, str_new);
      free(str);
      str = str_new;
    }
  }
  return str;
}
