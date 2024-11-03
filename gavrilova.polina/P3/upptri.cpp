#include "upptri.hpp"

bool isUpperTriangMtx (int * mtx, size_t m, size_t n)
{
  bool result = true;
  if (m != n) {
    return 0;
  }
  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; ++j) {
      if (!((j < i && mtx[i*n + j] == 0) || (j >= i))) {
        result = false;
      }
    }
  }
  return result;
}
