#ifndef TABLE_OUTPUT_HPP
#define TABLE_OUTPUT_HPP

#include <cstddef>

namespace maslevtsov
{
  void stringOutput(double current, size_t numberMax, double absError);
  void tableOutput(double left, double right, size_t numberMax, double step, double absError);
}

#endif
