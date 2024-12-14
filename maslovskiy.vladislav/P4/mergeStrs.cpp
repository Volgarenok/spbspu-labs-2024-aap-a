#include "mergeStrs.hpp"

void maslovskiy::mergeStrs(char* res, const char* first, const char* second)
{
  while (*first != '\0' && *second != '\0')
  {
    *res++ = *first++;
    *res++ = *second++;
  }
  while (*first != '\0')
  {
    *res++ = *first++;
  }
  while (*second != '\0')
  {
    *res++ = *second++;
  }
  *res = '\0';
}
