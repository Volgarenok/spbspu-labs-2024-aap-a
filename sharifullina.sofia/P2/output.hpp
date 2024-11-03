#ifndef OUTPUT_H
#define OUTPUT_H
#include <cstddef>
#include "cos_expnegx.h"

namespace sharifullina
{
  void output_row(auto i, double taylor, double cmath);
  void output_table(double left, double right, size_t k);
}
#endif
