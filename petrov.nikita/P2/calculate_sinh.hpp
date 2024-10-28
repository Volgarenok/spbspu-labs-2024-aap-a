#ifndef CALCULATE_SINH_HPP
#define CALCULATE_SINH_HPP
#include <iostream>

namespace petrov
{
  double calculateByTailor(double, size_t, double);
  double calculateBySTD(double);
  void outputTableHeader();
}
#endif

