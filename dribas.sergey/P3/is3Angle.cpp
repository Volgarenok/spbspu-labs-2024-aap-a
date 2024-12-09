#include "is3Angle.hpp"
#include <cstddef>

bool checkLine(const int* matrix, size_t M, size_t N, int variaty, size_t target)
{
  size_t count = 0;
  if (variaty == 1) {
    for (size_t i = M; matrix[i] == 0 && i <= N; i += 1) {
      count += 1;
    }
  }
  if (variaty == 2) {
    for (size_t i = N; matrix[i] == 0 && M <= i; i -= 1) {
      count += 1;
    }
  }
  if (count >= target) {
    return true;
  } else {
    return false;
  }
}

bool dribas::is3Angle(const int* matrix, size_t M, size_t N)
{
  if (M == 1 || M != N || M == 0) {
    return false;
  }
  bool result = false;
  for (int variaty = 1; variaty < 3; variaty += 1){
    bool preresult = true;
    for (size_t i = 0; i < M; i += 1){
      preresult = preresult && checkLine(matrix, i * M, ((i + 1) * M) - 1, variaty, M - 1 - i);
    }
    result = result || preresult;
  }
  return result;
}
