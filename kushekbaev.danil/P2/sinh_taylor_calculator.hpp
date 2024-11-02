#ifndef SINH_TAYLOR_CALCULATOR_H
#define SINH_TAYLOR_CALCULATOR_H
#include <cstddef>

namespace kushekbaev
{
  double taylorCalc(double x, size_t max_members, double error);
  double sinhCalc(double x);
}

#endif
