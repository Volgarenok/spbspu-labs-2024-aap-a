#ifndef SINH_TAYLOR_CALCULATOR_H
#define SINH_TAYLOR_CALCULATOR_H
#include <cmath>

namespace kushekbaev
{
  double taylorCalc(double x, size_t max_members, double error);
  double sinhCalc(double x, double error);
}

#endif
