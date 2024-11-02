#include "filemtx.h"
#include <iomanip>

void tkach::outputMtx(std::ostream & out, const double* const mtx, const size_t str)
{
  out << std::fixed;
  out << std::setprecision(1);
  out << mtx[0];
  for(size_t i = 1; i < str * str; ++i)
  {
    out << " " <<  mtx[i];
  }
}