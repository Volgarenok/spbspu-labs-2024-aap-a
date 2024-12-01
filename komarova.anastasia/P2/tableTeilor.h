#ifndef TABLETEILOR_H
#define TABLETEILOR_H
#include <cstddef>
namespace komarova
{
  double teilor(double x, const size_t  k, const double error);
  double lnTeilor(double x);
  void matherr(double x, double y);
  void output(double x, double value, double y);
}
#endif
