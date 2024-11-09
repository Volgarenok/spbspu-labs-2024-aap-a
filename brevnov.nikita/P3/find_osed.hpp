#ifndef FIND_OSED_HPP
#define FIND_OSED_HPP
#include <cstddef>

namespace brevnov
{
  int find_osed(const int * t, size_t m, size_t n);
  size_t find_index_min(const int * t, size_t n, size_t i);
  size_t find_index_max(const int * t, size_t m, size_t n, int min_member);
}
#endif
