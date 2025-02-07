#include "str_min_recursed.hpp"

namespace
{
  void sym_check(const char p, const char * a, size_t * b, size_t & k, size_t j, size_t & sym)
  {
    if (p == a[j])
    {
      b[j] += 1;
      k++;
      j = sym;
    }
    j++;
    if (j < sym)
    {
      sym_check(p, a, b, k, j, sym);
    }
  }

  void sym_counting(const char * str, char * a, size_t * b, size_t i, size_t size, size_t & sym)
  {
    size_t k = 0;
    char p = str[i];
    size_t j = 0;
    sym_check(p, a, b, k, j, sym);
    if (k == 0)
    {
      a[sym++] = p;
      b[sym - 1] = 1;
    }
    i++;
    if (i < size)
    {
      sym_counting(str, a, b, i, size, sym);
    }
  }

  size_t min_find(const size_t * sym_num, size_t i, size_t sym, size_t min, size_t & num)
  {
    if (sym_num[i] < sym_num[min])
    {
      min = i;
      num = 1;
    }
    else if (sym_num[i] == sym_num[min])
    {
      num++;
    }
    i++;
    if (i < sym)
    {
      min = min_find(sym_num, i, sym, min, num);
    }
    return min;
  }
}

char dirti::str_min_recursed(const char * str, size_t size)
{
  char symbols[256] = {'0'};
  size_t sym_num[256] = {0};
  symbols[0] = str[0];
  sym_num[0] = 1;
  size_t i = 1;
  size_t sym = 1;
  sym_counting(str, symbols, sym_num, i, size, sym);
  if (sym == 1)
  {
    return symbols[0];
  }
  size_t min = 0;
  size_t num = 1;
  i = 0;
  min = min_find(sym_num, i, sym, min, num);
  if (num > 1)
  {
    return '\n';
  }
  char sym_out = symbols[min];
  return sym_out;
}
