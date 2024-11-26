#include "upptri.hpp"
namespace gavrilova
{
  bool is_need_element(size_t i, size_t j, const int * mtx, size_t n);
}
bool gavrilova::isUpperTriangMtx(const int * mtx, size_t m, size_t n)
{
  bool result = true;
  if (m != n) {
    return false;
  }
  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; ++j) {
      if (!gavrilova::is_need_element(i, j, mtx, n)) {
        result = false;
      }
    }
  }
  return result;
}

bool gavrilova::is_need_element(size_t i, size_t j,  const int * mtx, size_t n)
{
  return ((j < i && !mtx[i * n + j]) || (j >= i));
}
