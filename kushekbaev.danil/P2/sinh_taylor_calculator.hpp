#ifndef SINH_TAYLOR_CALCULATOR_H
#define SINH_TAYLOR_CALCULATOR_H
#include <cstddef>
#include <ostream>

namespace kushekbaev
{
  void printWidth(std::ostream &os, size_t width, double value);
  void printResult(double value, size_t snd, size_t oth, size_t max_members, double error);
  double taylorCalc(double x, size_t max_members, double error);
  double sinhCalc(double x);
}

#endif
