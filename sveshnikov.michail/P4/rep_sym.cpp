#include "rep_sym.hpp"

char *sveshnikov::rep_sym(const char *str, char *new_str)
{
  std::size_t count = 0;
  for (std::size_t i = 0; str[i] != '\0'; i++)
  {
    std::size_t j = 0, k = 0, povtor = 0;
    while (new_str[k] != '\0' && povtor != 1)
    {
      if (str[i] == new_str[k])
      {
        povtor = 1;
      }
      k++;
    }
    if (povtor == 0)
    {
      while (str[j] != '\0' && povtor != 1)
      {
        if (str[i] == str[j] && i != j)
        {
          new_str[count] = str[i];
          povtor = 1;
          count++;
        }
        j++;
      }
    }
  }
  return new_str;
}
