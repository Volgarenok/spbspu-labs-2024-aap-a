#include "det_Num_Of_Letters.hpp"

#include <cctype>

size_t guseynov::determiningNumOfLetters(const char *inputString)
{
  size_t res = 0;
  for (size_t i = 0; inputString[i] != '\0'; i++)
  {
    if (std::isalpha(inputString[i]))
    {
      size_t f = 0;
      for (size_t j = 0; j < i; j++)
      {
        if (inputString[j] == inputString[i])
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
