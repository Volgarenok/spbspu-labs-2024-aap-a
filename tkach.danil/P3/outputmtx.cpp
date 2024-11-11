#include "filemtx.h"
#include <iostream>
#include <iomanip>

void tkach::outputMtx(std::ostream & out, const double* const mtx, const size_t row_size, const size_t column_size)
{
  out << row_size << " " << column_size;
  out << std::fixed;
  out << std::setprecision(1);
  for (size_t i = 0; i < row_size * column_size; ++i)
  {
    out << " " << mtx[i];
  }
}
