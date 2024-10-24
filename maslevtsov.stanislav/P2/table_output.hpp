#ifndef TABLE_OUTPUT_HPP
#define TABLE_OUTPUT_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <iomanip>

namespace maslevtsov
{
  void stringOutput(double current, size_t numberMax, const double absError);
  void tableOutput(double left, double right, size_t numberMax, const double step, const double absError);
}

#endif
