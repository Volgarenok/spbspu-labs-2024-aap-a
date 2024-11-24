#include "matrixInitiallization.hpp"
#include <stdexcept>

void asafov::initializationMatrixAuto(std::istream& in, int* mtx, unsigned long long& n, unsigned long long& m)
{
  in >> n;
  if (in.fail() || in.eof()) {
    throw std::logic_error("err");
  }
  in >> m;
  if (in.fail() || in.eof()) {
    throw std::logic_error("err");
  }
  for (size_t i = 0; i < n * m; i++) {
    in >> mtx[i];
    if (in.fail() || in.eof()) {
      throw std::logic_error("err");
    }
  }
}
