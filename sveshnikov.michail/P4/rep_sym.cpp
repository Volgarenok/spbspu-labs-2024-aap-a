#include "rep_sym.hpp"

char *sveshnikov::rep_sym(const char *str, char *new_str)
{
  std::size_t count = 0;
  for (std::size_t i = 0; str[i] != '\0'; i++)
  {
    std::size_t j = 0, k = 0, povtor = 0;
    if (str[i] == new_str[k])
    {
      povtor = 1;
    }
    while (new_str[k] != '\0' && str[i] != new_str[k] && povtor != 1)
    {
      if (str[i] == new_str[k + 1])
      {
        povtor = 1;
      }
      k++;
    }
    if (povtor == 0)
    {
      if (str[i] == str[j])
      {
        new_str[count] = str[i];
        new_str[count + 1] = '\0';
        count++;
      }
      while (str[j] != '\0' && str[i] != str[j])
      {
        if (str[i] == str[j + 1])
        {
          new_str[count] = str[i];
          new_str[count + 1] = '\0';
          count++;
        }
        j++;
      }
    }
  }
  new_str[count] = '\0';
  return new_str;
}
