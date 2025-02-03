#include "str_min2.hpp"
#include "str_min.hpp"

char * dirti::str_min2(const char * str, size_t size)
{
  if (str == nullptr || size == 0)
  {
    return nullptr;
  }
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
  size_t sym = 1;
  dirti::sym_count(str, sym_name, sym_num, size, sym);
  size_t str_min2_size = 2;
  char * str_min2 = reinterpret_cast< char * >(malloc(sizeof(char) * str_min2_size));
  if (str_min2 == nullptr)
  {
    return nullptr;
  }
  str_min2[0] = sym_sym[0];
  size_t min = size + 1;
  for (size_t i = 0; i < sym; ++i)
  {
    if (sym_num[i] < min)
    {
      min = sym_num[i];
      str_min2[1] = str_min2[0];
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
