#ifndef FUNC_H
#define FUNC_H
#include <cstddef>
namespace asafov {
  double absError(double x, std::size_t k);
  double expNegPow2x(double x, std::size_t k, double error);
  void table(double left, double right, double step, std::size_t numberMax, double error);
}
#endif
