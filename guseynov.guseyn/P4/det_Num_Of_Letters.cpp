#include "det_Num_Of_Letters.hpp"

#include <cctype>

size_t guseynov::determiningNumOfLetters(const char *inputString)
{
  size_t res = 0;
  size_t f = 0;
  size_t i = 0;
  while (inputString[i++] != '\0')
  {
    if (isalpha (inputString[i - 1]))
    {
      for (size_t j = 0; j < (i - 1); j++)
      {
        if (inputString[j] == inputString[i - 1])
        {
          f = 1;
        }
      }
      if (f != 0)
      {
        f = 0;
      }
      else
      {
        res++;
      }
    }
  }
  return res;
}
