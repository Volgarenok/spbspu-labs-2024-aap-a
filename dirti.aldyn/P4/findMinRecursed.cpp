#include "findMinRecursed.hpp"

namespace
{
  void checkSym(const char p, const char * a, size_t * b, size_t & k, size_t j, size_t & sym)
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
      checkSym(p, a, b, k, j, sym);
    }
  }

  void countingSym(const char * str, char * a, size_t * b, size_t i, size_t & sym)
  {
    size_t k = 0;
    char p = *(str + i);
    size_t j = 0;
    checkSym(p, a, b, k, j, sym);
    if (k == 0)
    {
      a[sym++] = p;
      b[sym - 1] = 1;
    }
    i++;
    if (*(str + i) != '\0')
    {
      countingSym(str, a, b, i, sym);
    }
  }

  size_t findingMin(const size_t * sym_num, size_t i, size_t sym, size_t min)
  {
    if (sym_num[i] <= sym_num[min])
    {
      min = i;
    }
    i++;
    if (i < sym)
    {
      min = findingMin(sym_num, i, sym, min);
    }
    return min;
  }
}

char dirti::findMinRecursed(const char * str)
{
  char symbols[256] = {'0'};
  size_t sym_num[256] = {0};
  symbols[0] = str[0];
  sym_num[0] = 1;
  size_t i = 1;
  size_t sym = 1;
  countingSym(str, symbols, sym_num, i, sym);
  size_t min = 0;
  i = 0;
  min = findingMin(sym_num, i, sym, min);
  char sym_out = symbols[min];
  return sym_out;
}
