#ifndef COS_EXPNEGX_HPP
#define COS_EXPNEGX_HPP
#include <cstddef>

namespace sharifullina
{
  double cos(double x, size_t k, double error);
  double exp_negx(double x, size_t k, double error);
  double cos_and_exp(double x, size_t k, double error);
  double cos_cmath(double x);
  double exp_negx_cmath(double x);
  double cos_and_exp_cma(double x);
}
#endif
