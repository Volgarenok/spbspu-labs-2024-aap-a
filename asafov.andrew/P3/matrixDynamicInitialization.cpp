#include "matrixInitiallization.hpp"
#include <stdexcept>

int* asafov::initializationMatrixDynamic(std::istream& in, unsigned long long& n, unsigned long long& m)
{
  in >> n;
  if (in.fail() || in.eof()) {
    throw std::logic_error("err");
  }
  in >> m;
  if (in.fail() || in.eof()) {
    throw std::logic_error("err");
  }
  mtx = new int[n * m];
  for (size_t i = 0; i < n * m; i++) {
    in >> mtx[i];
    if (in.fail() || in.eof()) {
      throw std::logic_error("err");
    }
  }
  return mtx;
}
