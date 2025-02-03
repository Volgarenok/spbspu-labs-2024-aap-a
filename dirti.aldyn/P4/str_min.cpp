#include "str_min.hpp"

void dirti::sym_count(const char * str, char * sym_name, char * sym_num, size_t size, size_t & sym)
{
  size_t k = 0;
  for (size_t i = 1; i < size; ++i)
  {
    k = 0;
    for (size_t j = 0; j < sym; ++j)
    {
      if (str[i] == sym_name[j])
      {
        sym_num[j] += 1;
        k++;
        break;
      }
    }
    if (k == 0)
    {
      sym_name[sym++] = str[i];
      sym_num[sym - 1] = 1;
    }
  }
}

char dirti::str_min(const char * str, size_t size)
{
  if (str == nullptr || size = 0)
  {
    return '\0';
  }
  char * sym_name = reinterpret_cast< char * >(malloc(sizeof(char) * size));
  if (sym_name == nullptr)
  {
    return '\0';
  }
  size_t * sym_num = reinterpret_cast< size_t * >(malloc(sizeof(size_t) * size));
  if (sym_num == nullptr)
  {
    free(sym_name);
    return '\0';
  }
  sym_name[0] = str[0];
  sym_num[0] = 1;
  size_t sym = 1;
  dirti::sym_count(str, sym_name, sym_num, size, sym);
  size_t min = size + 1;
  size_t num = 0;
  char sym_out = 'a';
  for (size_t i = 0; i < sym; ++i)
  {
    if (sym_num[i] < min)
    {
      min = sym_num[i];
      sym_out = sym_name[i];
      num = 1;
    }
    else if (sym_num[i] == min)
    {
      num++;
    }
  }
  if (num > 1)
  {
    free(sym_name);
    free(sym_num);
    return '\n';
  }
  free(sym_name);
  free(sym_num);
  return sym_out;
}
