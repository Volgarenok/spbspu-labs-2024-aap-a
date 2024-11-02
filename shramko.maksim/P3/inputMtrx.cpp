#include "inputMtrx.hpp"

std::istream & shramko::inputMtrx(std::istream & in, int* mtrx, size_t cnt_row, size_t cnt_col, int& read)
{
  for (size_t i = 0; i < (cnt_row * cnt_col); ++i)
  {
    in >> mtrx[i];
    ++read;
  }
  return in;
}
