#include "is3Angle.hpp"
#include <cstddef>

bool is3Angle(int* matrix, size_t M, size_t N)
{
  if (M == 1 || M != N) {
    return 0;
  }
  bool res2 = 1, res1 = 1;

  for (size_t i = 0; i < M; i += 1) {
    for (size_t j = i * M + (i + 1); j < (i + 1) * M; j += 1) {
      if (matrix[j] != 0) {
        res1 = 0;
        break;
      }
    }
  }
  for (size_t i = 0; i < M; i += 1) {
    for (size_t j = (i * M); j < ((i + 1) * M) - i - 1; j += 1) {
      if (matrix[j] != 0) {
        res2 = 0;
        break;
      }
    }
  }
  res2 = res2||res1;

  return res2;
}
