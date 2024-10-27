#ifndef CREATINGTABLES_HPP
#define CREATINGTABLES_HPP
#include <cstddef>
#include <iostream>
#include <iomanip>

namespace zakirov
{
  void zakirov::tylor_string(double point, size_t addition_depth, const double error);
  void zakirov::tylor_table(double left, double right, size_t addition_depth,
  const double kStep, const double kError);
}

#endif