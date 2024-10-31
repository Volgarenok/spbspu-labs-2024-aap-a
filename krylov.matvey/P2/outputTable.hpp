#ifndef OUTPUTTABLE_HPP
#define OUTPUTTABLE_HPP

#include <cstddef>

namespace krylov
{
  void lineOutput(double x, size_t max_terms_number, double error);
  void tableOutput(double left_border, double right_border, size_t max_terms_number, double step, double error);
}

#endif
