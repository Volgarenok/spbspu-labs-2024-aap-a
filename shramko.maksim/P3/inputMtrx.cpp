#include "inputMtrx.hpp"

std::istream & shramko::inputMtrx(std::istream & in, int* mtrx, size_t sizeMtrx)
{
  size_t dataCnt = 0;
  for (size_t i = 0; i < sizeMtr; ++i)
  {
    in >> mtrx[i];
  }

  return in;
}
