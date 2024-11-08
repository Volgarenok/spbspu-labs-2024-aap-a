#ifndef TAYLORCALC_HPP
#define TAYLORCALC_HPP
#include <cstddef>

namespace shabalin
{
  double taylorViaCos(double x, size_t k, double error);
  void output(double x, size_t k, double error);
  void finalOutput(double left, double right, double step, size_t k, double error);
}

#endif
