#ifndef ARCTAN_TAYLOR_H
#define ARCTAN_TAYLOR_H
#include <cstddef>
namespace timofeev
{
  double arctanTaylor(double x, double absError, size_t numberMax);
  void MatrixOutput(double start, double end, size_t numberMax, double absError, double step);
}
#endif
