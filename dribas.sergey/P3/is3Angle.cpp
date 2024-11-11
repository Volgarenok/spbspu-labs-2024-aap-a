#include "is3Angle.hpp"
#include <cstddef>

bool dribas::checkLine(int const* matrix, size_t M, size_t N, int variaty, size_t target)
{
  size_t result = 0;

  if (variaty == 1){
    for (size_t i = M; matrix[i] != 0 || i == N; i += 1){
      result += 1;
    }
  }
  if (variaty == 2){
    for (size_t i = N; matrix[i] != 0 || i == M; i -= 1){
      result += 1;
    }
  }
  return result>=target;
}

bool dribas::is3Angle(int const* matrix, size_t M, size_t N)
{
  if (M == 1 || M != N || M == 0) {
    return false;
  }
  bool result = false;
  for (int variaty = 1; variaty < 3; variaty += 1){
    bool preresult = true;
    for (size_t i = 0; i < M; i += 1){
      preresult = preresult && dribas::checkLine(matrix,i * M, (i + 1) * M, variaty, M-1-i);
    }
    result = result || preresult;
  }
  return result;
}
