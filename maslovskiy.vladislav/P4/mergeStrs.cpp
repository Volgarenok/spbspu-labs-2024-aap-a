#include "mergeStrs.hpp"

void maslovskiy::mergeStrs(char* result, const char* first, const char* second)
{
  while (*first != '\0' && *second != '\0')
  {
    *result++ = *first++;
    *result++ = *second++;
  }
  while (*first != '\0')
  {
    *result++ = *first++;
  }
  while (*second != '\0')
  {
    *result++ = *second++;
  }
  *result = '\0';
}
