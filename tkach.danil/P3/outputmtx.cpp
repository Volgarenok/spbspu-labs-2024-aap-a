#include "filemtx.h"
#include <iostream>
#include <iomanip>

void tkach::outputMtx(std::ostream & out, const double* const mtx, const size_t str, const size_t stl)
{
  if (mtx == nullptr)
  {
    std::cerr << "Out of memory\n";
    return;
  }
  out << str << " " << stl;
  out << std::fixed;
  out << std::setprecision(1);
  for (size_t i = 0; i < str * stl; ++i)
  {
    out << " " << mtx[i];
  }
  delete[] mtx;
}
