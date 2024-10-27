#ifndef TYLER_DERDEN_H
#define TYLER_DERDEN_H
#include <cstddef>
namespace finaev
{
  double fsqrt(double x, size_t k, double error);
  double basesqrt(double x);
  void final_output(double left, double right, size_t k, double error, double step);
}
#endif
