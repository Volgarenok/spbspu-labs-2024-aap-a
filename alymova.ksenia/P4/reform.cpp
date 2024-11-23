#include "reform.h"
#include <cstddef>
#include <cctype>
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
