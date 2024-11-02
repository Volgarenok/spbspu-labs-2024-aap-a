#include "inputMtrx.hpp"

std::istream & shramko::inputMtrx(std::istream & in, int* mtrx, size_t cnt_row, size_t cnt_col, size_t sizeMtr)
{
  size_t dataCnt = 0;
  for (size_t i = 0; i < sizeMtr; ++i)
  {
    in >> mtrx[i];
    ++dataCnt;
  }

  if (dataCnt != sizeMtr)
  {
    throw;
  }

  return in;
}
