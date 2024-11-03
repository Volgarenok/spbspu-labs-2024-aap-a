#ifndef CALCULATE_SINH_HPP
#define CALCULATE_SINH_HPP
#include <cstddef>

namespace petrov
{
  double calculateByTaylor(double x, size_t max, double error);
  double calculateBySTD(double x);
  void outputTable(double start, double end, size_t max, double error, double step);
  void outputFirstColumn(double x);
  void outputSecondColumn(double x, size_t max, double error);
  void outputThirdColumn(double x);
}
#endif

