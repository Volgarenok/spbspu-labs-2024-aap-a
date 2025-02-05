#ifndef MATH_HPP
#define MATH_HPP

namespace rychkov
{
  bool isAlmostEqual(double a, double b, double coef);
  double getEpsilon(double num, bool toPlusInfinity);
  constexpr double PI = 3.14159265358979323846;
}

#endif
