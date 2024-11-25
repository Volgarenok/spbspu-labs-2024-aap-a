#include "matrixInitiallization.hpp"
#include <stdexcept>

void asafov::initializationMatrix(std::istream& in, int* mtx, unsigned long long& n, unsigned long long& m)
{
  for (size_t i = 0; i < n * m; i++) {
    in >> mtx[i];
    if (in.fail() || in.eof()) {
      throw std::logic_error("err");
    }
  }
}
