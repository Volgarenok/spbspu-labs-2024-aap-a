#ifndef FUNC_H
#define FUNC_H
#include <cstddef>
namespace asafov {
  double countAbsoluteError(double x, std::size_t k);
  double countExpNegPow2x(double x, std::size_t k, double error);
  void output(double left, double right, double step, std::size_t numberMax, double error);
}
#endif
