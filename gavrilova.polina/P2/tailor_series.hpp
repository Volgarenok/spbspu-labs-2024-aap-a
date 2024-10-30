#include <iostream>
#ifndef TAYLORSERIES_HPP
#define TAYLORSERIES_HPP

namespace gavrilova
{
  double v_taylor(double x, size_t nMax, double error);
  double v_cmath(double x);
  void output_str(double num, double v_taylor, double v_cmath);
  void output_str(double num, const char *, double v_cmath);
}
#endif

