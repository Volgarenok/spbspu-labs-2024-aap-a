#include "filemtx.h"

std::istream & tkach::inputMtx(std::istream & in, int* const mtx1, const size_t row_size, const size_t column_size)
{
  for (size_t i = 0; i < row_size; ++i)
  {
    for (size_t j = 0; j < column_size; ++j)
    {
      in >> mtx1[i * column_size + j];
    }
  }
  return in;
}
