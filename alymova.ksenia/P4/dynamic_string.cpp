#include "dynamic_string.h"
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <cstdlib>
char* alymova::copy_string(const char* str, char* str_new)
{
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    str_new[i] = str[i];
  }
  return str_new;
}
char* alymova::upper_string(const char* str, char* str_res)
{
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    if (std::islower(str[i]))
    {
      str_res[i] = static_cast< char >(std::toupper(str[i]));
    }
    else
    {
      str_res[i] = str[i];
    }
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
      str_new = alymova::copy_string(str, str_new);
      free(str);
      str = str_new;
    }
  }
  return str;
}
