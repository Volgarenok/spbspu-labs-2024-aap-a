#include "is3Angle.hpp"
#include <cstddef>

bool dribas::is3Angle(int* matrix, size_t M, size_t N)
{
  if (M == 1 || M != N || M == 0) {
    return false;
  }
  bool res2 = true, res1 = true;

  for (size_t i = 0; i < M; i += 1) {
    for (size_t j = i * M + (i + 1); j < (i + 1) * M; j += 1) {
      if (matrix[j] != 0) {
        res1 = false;
        break;
      }
    }
  }
  for (size_t i = 0; i < M; i += 1) {
    for (size_t j = (i * M); j < ((i + 1) * M) - i - 1; j += 1) {
      if (matrix[j] != 0) {
        res2 = false;
        break;
      }
    }
  }
  res2 = res2||res1;

  return res2;
}
