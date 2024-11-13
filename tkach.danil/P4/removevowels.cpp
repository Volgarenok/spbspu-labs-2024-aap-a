#include "logic.h"

size_t tkach::getStrWithRemovedVowels(const char* str, char* str2)
{
  constexpr char str3[] = "eyuioaEYUIOA";
  size_t numberforstr2 = 0;
  size_t amountofdeleted = 0;
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    int flag = 1;
    for (size_t j = 0; str3[j] != '\0'; ++j)
    {
      if (str[i] == str3[j])
      {
        flag = 0;
        amountofdeleted++;
        break;
      }
    }
    if (flag == 1)
    {
      str2[numberforstr2++] = str[i];
    }
  }
  str2[numberforstr2] = '\0';
  return amountofdeleted;
}
