#ifndef TAYLOR_SWIFT_H
#define TAYLOR_SWIFT_H
#include <cstddef>
namespace lanovenko
{
  double f(double x, size_t k, double error);
  double sqruno(double x);
  void laststro(double left, double right, size_t k, double error, double step);
}
#endif

