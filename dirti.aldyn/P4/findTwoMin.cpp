#include "findTwoMin.hpp"
#include <cstddef>

namespace
{
  void countSym(const char* str, char* symbols, size_t* sym_num, size_t& sym)
  {
    symbols[0] = *str;
    sym_num[0] = 1;
    size_t k = 0;
    size_t i = 1;
    while (*(str + i) != '\0')
    {
      k = 0;
      for (size_t j = 0; j < sym; ++j)
      {
        if (*(str + i) == symbols[j])
        {
          sym_num[j] += 1;
          k++;
          break;
        }
      }
      if (k == 0)
      {
        symbols[sym] = *(str + i);
        sym_num[sym] = 1;
        sym++;
      }
      i++;
    }
  }
}

void dirti::findTwoMin(const char * str, char * str_min2)
{
  str_min2[0] = str[0];
  char symbols[256] = {'0'};
  size_t sym_num[256] = {0};
  size_t sym = 1;
  countSym(str, symbols, sym_num, sym);
  size_t min = 0;
  for (size_t i = 0; i < sym; ++i)
  {
    if (sym_num[i] <= sym_num[min])
    {
      min = i;
      str_min2[1] = str_min2[0];
      str_min2[0] = symbols[i];
    }
  }
}
