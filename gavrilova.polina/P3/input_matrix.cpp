#include "upptri.hpp"
#include <cstddef>
#include <istream>

std::istream & gavrilova::input_matrix(std::istream & in, int * mtx, size_t m, size_t n, size_t & read)
{
  if (m == 0 || n == 0) {
    return in;
  }
  for (size_t i = 0; i < m; ++i) {
    for (size_t j = 0; j < n; ++j) {
      if (in >> mtx[i * n + j]) {
        ++read;
      } else {
        return in;
      }
    }
  }

  return in;
}
