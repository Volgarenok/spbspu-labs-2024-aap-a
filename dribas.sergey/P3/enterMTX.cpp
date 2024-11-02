#include "enterMTX.hpp"
#include <cstddef>
#include <istream>

std::istream & dribas::enterMTX(std::istream & in, int* mtx, size_t M, size_t N, size_t& readed)
{
  for (size_t i = 0; i < M * N; i += 1) {
    if (in >> mtx[i]) {
      readed += 1;
    } else {
      return in;
    }
  }
  return in;
}
