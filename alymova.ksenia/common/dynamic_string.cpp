#include "dynamic_string.h"
#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <cstdlib>
<<<<<<< HEAD
/*char* alymova::create(size_t size)
{
  char* str = reinterpret_cast< char* >(malloc((size + 1) * sizeof(char)));
  if (str == nullptr)
  {
    return str;
  }
  str[size] = '\0';
  return str;
}*/
char* alymova::copy_string(const char* str, char* str_new)
{
  for (size_t i = 0; str[i] != '\0'; i++)
=======
char* alymova::copy_string(const char* str, size_t end, char* str_new)
{
  char* ptr_new = str_new;
  const char* ptr = str;
  for (; ptr != (str + end); ptr++)
>>>>>>> alymova.ksenia/P4
  {
    *ptr_new = *ptr;
    ptr_new += 1;
  }
  return str_new;
}
<<<<<<< HEAD
char* alymova::upper_string(const char* str, char* str_res)
=======
char* alymova::get_string(size_t& size, size_t& size_now, int ratio, char delim)
>>>>>>> alymova.ksenia/P4
{
  char* str = reinterpret_cast< char* >(malloc((size + 1) * sizeof(char)));
  if (str == nullptr)
  {
<<<<<<< HEAD
    if (std::islower(str[i]))
    {
      str_res[i] = static_cast< char >(std::toupper(str[i]));
    }
    else
    {
      str_res[i] = str[i];
    }
  }
  return str;
}
char* alymova::get_string(size_t& size, size_t& size_now, int ratio, char delim)
{
  char* str = reinterpret_cast< char* >(malloc((size + 1) * sizeof(char)));
  if (str == nullptr)
  {
    return nullptr;
  }
=======
    return nullptr;
  }
>>>>>>> alymova.ksenia/P4
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
<<<<<<< HEAD
      str_new = alymova::copy_string(str, str_new);
=======
      str_new = alymova::copy_string(str, size / ratio, str_new);
>>>>>>> alymova.ksenia/P4
      free(str);
      str = str_new;
    }
  }
  return str;
}
