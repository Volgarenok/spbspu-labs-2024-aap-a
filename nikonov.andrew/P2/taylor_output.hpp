#ifndef TAYLOR_OUTPUT_HPP
#define TAYLOR_OUTPUT_HPP
#include <stdexcept>
#include <cstddef>
#include <iostream>
namespace nikonov
{
  void stringOutput(double x, double numberMax, double absError);
  std::ostream& setWidth(std::ostream& out, size_t num, size_t col_width);
  void table_output(double left, double right, double step, double numberMax, double absError);
}
#endif
