#include "rep_sym.hpp"

char *sveshnikov::rep_sym(char *str, char *new_str)
{
  std::size_t count = 0;
  for (std::size_t i = 0; str[i + 1] != '\n'; i++)
  {
    for (std::size_t j = i + 1; str[j] != '\n'; j++)
    {
      if (str[i] == str[j])
      {
        for (std::size_t k = 0; new_str[k] != '\n'; k++)
        {
          if (str[i] == new_str[k])
          {
            
          }
        }
      }
    }
  }
}
