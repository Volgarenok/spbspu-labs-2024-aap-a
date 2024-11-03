#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <cstddef>
#include "cos_expnegx.hpp"

namespace sharifullina
{
  void output_row(double i, size_t k, double error);
  void output_table(double left, double right, size_t k, double step, double error);
}
#endif
