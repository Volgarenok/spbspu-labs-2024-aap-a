#include "rep_sym.hpp"

char *sveshnikov::rep_sym(const char *str, char *new_str)
{
  std::size_t count = 0;
  for (std::size_t i = 0; str[i + 1] != '\n'; i++)
  {
    std::size_t j = i, k = 1, povtor = 0;
    while (str[k] != '\n' || str[i] != str[k - 1])
    {
      if (str[i] != str[k - 1])
      {
        povtor = 1;
      }
      k++;
    }
    if (povtor == 0)
    {
      while (str[j] != '\n' || str[i] != str[j])
      {
        if (str[i] == str[j + 1])
        {
          new_str[count] = str[i];
          count++;
        }
        j++;
      }
    }
  }
  return new_str;
}
