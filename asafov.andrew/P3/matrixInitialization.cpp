#include "matrixInitiallization.hpp"
#include <stdexcept>

void asafov::initializeMatrix(std::istream& in, int* mtx, const unsigned long long n, const unsigned long long m)
{
  for (size_t i = 0; i < n * m; i++) {
    in >> mtx[i];
    if (in.fail() || in.eof()) {
      throw std::logic_error("err");
    }
  }
}
