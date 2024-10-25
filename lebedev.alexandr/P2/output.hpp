#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include "taylor_swift.hpp"

namespace lebedev
{
  void output_raw (double x, size_t k, double error);
  void output_table (double left, double right, size_t k, double error, double step);
}
#endif
