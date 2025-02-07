#include "str_min2.hpp"
#include "str_min.hpp"

void dirti::str_min2(const char * str, size_t size, char * str_min2)
{
  char symbols[256] = {'0'};
  size_t sym_num[256] = {0};
  size_t sym = 1;
  dirti::sym_count(str, symbols, sym_num, size, sym);
  str_min2[0] = symbols[0];
  size_t min = size + 1;
  for (size_t i = 1; i < sym; ++i)
  {
    if (sym_num[i] <= min)
    {
      min = sym_num[i];
      str_min2[1] = str_min2[0];
      str_min2[0] = symbols[i];
    }
  }
}
