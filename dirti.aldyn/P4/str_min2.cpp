#include "str_min2.hpp"


char * dirti::str_min2(const char * str, const size_t size)
{
  size_t sym = 1;
  char * sym_sym = reinterpret_cast< char * >(malloc(sizeof(char) * size));
  if (sym_sym == nullptr)
  {
    return nullptr;
  }
  size_t * sym_num = reinterpret_cast< size_t * >(malloc(sizeof(size_t) * size));
  if (sym_num == nullptr)
  {
    return nullptr;
  }
  sym_sym[0] = str[0];
  sym_num[0] = 1;
  size_t k = 0;
  size_t str_min2_size = 2;
  char * str_min2 = reinterpret_cast< char * >(malloc(sizeof(char) * str_min2_size));
  if (str_min2 == nullptr)
  {
    return nullptr;
  }
  for (size_t i = 1; i < size; ++i)
  {
    k = 0;
    for (size_t j = 0; j < sym; ++j)
    {
      if (str[i] == sym_sym[j])
      {
        sym_num[j] += 1;
        k++;
        break;
      }
    }
    if (k == 0)
    {
      sym_sym[sym++] = str[i];
      sym_num[sym - 1] = 1;
    }
  }
  size_t min = size + 1;
  for (size_t i = 0; i < sym; ++i)
  {
    if (sym_num[i] < min)
    {
      min = sym_num[i];
      str_min2[0] = sym_sym[i];
    }
    else if (sym_num[i] == min)
    {
      str_min2[1] = sym_sym[i];
    }
  }
  free(sym_sym);
  free(sym_num);
  return str_min2;
}
