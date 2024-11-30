#include "mergeStrs.hpp"

void fillStr(char *res, const char *str, size_t pos)
{
  size_t i = 0;
  for (i = pos * 2; str[pos] != '\0'; ++i)
  {
    res[i] = str[pos];
    ++pos;
  }
  res[i] = '\0';
}
void maslovskiy::mergeStrs(char *res, const char *first, const char *second)
{
  size_t i = 0;
  for (; first[i] != '\0' && second[i] != '\0'; ++i)
  {
    res[i * 2] = first[i];
    res[i * 2 + 1] = second[i];
  }
  const char *temp = first[i] != '\0' ? first : second;
  fillStr(res, temp, i);
}

