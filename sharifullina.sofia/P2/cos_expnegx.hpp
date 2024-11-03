#ifndef COS_EXPNEGX_H
#define COS_EXPNEGX_H
#include <cstddef>

namespace sharifullina

{
  double cos(double x, size_t k, double error);
  double exp_negx(double x, size_t k, double error);
  double cos_cmath(double x);
  double exp_negx_cmath(double x);
}

#endif
