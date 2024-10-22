#ifndef TABLE_OUTPUT_HPP
#define TABLE_OUTPUT_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <cmath>

namespace maslevtsov
{
  void stringOutput(double current, size_t k, const double error);
  void tableOutput(double left, double right, size_t k, const double step, const double error);
}

#endif