#include "makeMatrix.cpp"
#include <stdexcept>
#include "cstddef"

bool dribas::makeMatrix(int arg, int * mtx, size_t M, size_t N)
{
  if (arg == 1) {
    mtx = int[10000];
    return 1;
  } else {
    try {
      mtx = new int[M * N];
    } catch (const bad_alloc & e) {
      return 0;
    }
  }
}
