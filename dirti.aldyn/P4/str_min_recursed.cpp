#include "str_min_recursed.hpp"

namespace
{
  void symbols2(const char p, char * a, size_t * b, size_t & k, size_t j, size_t & sym)
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
      symbols2(p, a, b, k, j, sym);
    }
  }

  void symbols(const char * str, char * a, size_t * b, size_t i, const size_t size, size_t & sym)
  {
    size_t k = 0;
    char p = str[i];
    size_t j = 0;
    symbols2(p, a, b, k, j, sym);
    if (k == 0)
    {
      a[sym++] = p;
      b[sym - 1] = 1;
    }
    i++;
    if (i < size)
    {
      symbols(str, a, b, i, size, sym);
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

char dirti::str_min_recursed(const char * str, const size_t size)
{
  size_t sym = 1;
  char * sym_sym = reinterpret_cast< char * >(malloc(sizeof(char) * size));
  if (sym_sym == nullptr)
  {
    return '\0';
  }
  size_t * sym_num = reinterpret_cast< size_t * >(malloc(sizeof(size_t) * size));
  if (sym_num == nullptr)
  {
    free(sym_sym);
    return '\0';
  }
  sym_sym[0] = str[0];
  sym_num[0] = 1;
  size_t i = 1;
  symbols(str, sym_sym, sym_num, i, size, sym);
  size_t min = 0;
  size_t num = 0;
  i = 0;
  min = min_find(sym_num, i, sym, min, num);
  if (num > 1)
  {
    free(sym_sym);
    free(sym_num);
    return '\n';
  }
  char sym_out = sym_sym[min];
  free(sym_sym);
  free(sym_num);
  return sym_out;
}
