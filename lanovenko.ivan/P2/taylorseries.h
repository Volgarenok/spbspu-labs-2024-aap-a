#ifndef TAYLORSERIES_H
#define TAYLORSERIES_H
#include <cstddef>
namespace lanovenko
{
  double f(double x, size_t k, double error);
  double sqruno(double x);
  void table(double left, double right, size_t k, double error, double step);
}
#endif

