#include "logic.h"
#include <cstdlib>

void tkach::getStrWithRemovedVowels(const char* str, char* str2)
{
  constexpr char str3[] = "eyuioa";
  size_t numberforstr2 = 0;
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    int flag = 1;
    for (size_t j = 0; j < 6; ++j)
    {
      if (str[i] == str3[j])
      {
        flag = 0;
        break;
      }
    }
    if (flag == 1)
    {
      str2[numberforstr2++] = str[i];
    }
  }
}
