#ifndef CALCULATE_SINH_HPP
#define CALCULATE_SINH_HPP
#include <cstddef>

namespace petrov
{
  double calculateByTailor(double, size_t, double);
  double calculateBySTD(double);
  void outputTableHeader();
}
#endif

