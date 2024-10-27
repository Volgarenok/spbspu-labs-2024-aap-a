#ifndef VALUESOUTPUT_HPP
#define VALUESOUTPUT_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <iomanip>

namespace krylov
{
  void lineOutput(double x, size_t max_terms_number, double error);
  void tableOutput(double left_border, double right_border, size_t max_terms_number, double step, double error);
}

#endif
