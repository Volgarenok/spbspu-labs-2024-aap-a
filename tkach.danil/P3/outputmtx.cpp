#include "filemtx.h"
#include <iomanip>

void tkach::outputMtx(std::ostream & out, const double* const mtx, const size_t str)
{
  out << str << " " << str;
  out << std::fixed;
  out << std::setprecision(1);
  for (size_t i = 0; i < str * str; ++i)
  {
    out << " " << mtx[i];
  }
  delete[] mtx;
}
