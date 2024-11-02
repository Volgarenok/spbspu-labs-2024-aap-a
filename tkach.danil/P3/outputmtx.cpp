#include "filemtx.h"
#include <iomanip>

void tkach::outputMtx(std::ostream & out, const double* const mtx, const size_t str, size_t stl)
{
  out << str << " " << stl;
  out << std::fixed;
  out << std::setprecision(1);
  for (size_t i = 0; i < str * stl; ++i)
  {
    out << " " << mtx[i];
  }
  delete[] mtx;
}
