#ifndef CALCULATE_SINH_HPP
#define CALCULATE_SINH_HPP
#include <cstddef>

namespace petrov
{
  double calculateByTailor(double x, size_t max, double error);
  double calculateBySTD(double x);
  void outputTableHeader();
}
#endif

