#include "reform.h"
#include <cctype>
char* alymova::upper_string(const char* str, char* str_res)
{
  char* ptr_res = str_res;
  for (; *str != '\0'; str++)
  {
    if (std::islower(*str))
    {
      *ptr_res = static_cast< char >(std::toupper(*str));
    }
    else
    {
      *ptr_res = *str;
    }
    ptr_res++;
  }
  return str_res;
}
