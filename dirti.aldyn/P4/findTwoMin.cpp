#include "findTwoMin.hpp"
#include "findMin.hpp"

void dirti::findTwoMin(const char * str, char * str_min2)
{
  str_min2[0] = dirti::findMin(str);
  char newStr[10000] = {'\0'};
  size_t j = 0;
  for (size_t i = 0; *(str + i) != '\0'; ++i)
  {
    if (*(str + i) != str_min2[0])
    {
      newStr[j++] = *(str + i);
    }
  }
  str_min2[1] = dirti::findMin(newStr);
}
