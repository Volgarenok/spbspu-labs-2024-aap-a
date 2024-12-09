#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <cstddef>

namespace belobrov
{
  void output(double left, double right, double step, size_t k, double error);
  void table_out(double n, size_t k, double error);
  void parameters_output(double n);
}

#endif
