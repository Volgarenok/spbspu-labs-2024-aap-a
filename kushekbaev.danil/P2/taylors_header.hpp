#ifndef TAYLORS_HEADER_H
#define TAYLORS_HEADER_H
#include <cmath>

namespace kushekbaev
{
  double taylorCalc(double x, size_t max_members, double error);
  double sinhCalc(double x);
}

#endif
