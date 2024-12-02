#include "mergeStrs.hpp"

void fillStr(char *res, const char *str)
{
  while (*str != '\0')
  {
    *res = *str;
    ++res;
    ++str;
  }
  *res = '\0';
}
void maslovskiy::mergeStrs(char *res, const char *first, const char *second)
{
  while (*first != '\0' && *second != '\0')
  {
    *res++ = *first++;
    *res++ = *second++;
  }
  fillStr(res, (*first != '\0') ? first : second);
}
