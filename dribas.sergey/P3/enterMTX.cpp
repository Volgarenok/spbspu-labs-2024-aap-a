#include "enterMTX.cpp"
#include <cstddef>
#include <istream>

std::ifstream & dribas::enterMTX(std::istream & in, int * mtx, size_t M, size_t N, size_t& readed)
{
  for (size_t i = 0; i < M * N; i += 1) {
    if (in >> mtx[i]) {
      read += 1;
    } else {
      return in;
    }
  }
  return in;
}
