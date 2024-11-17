#ifndef COS_EXPNEGX_HPP
#define COS_EXPNEGX_HPP
#include <cstddef>

namespace sharifullina
{
  double cos(double x, size_t k, double error);
  double exp_negx(double x, size_t k, double error);
  double cos_and_exp(double x, size_t k, double error)
  {
    return cos(x, k, error) + exp_negx(x, k, error);
  }
  double cos_cmath(double x);
  double exp_negx_cmath(double x);
  double cos_and_exp_cma(double x)
  {
    return cos_cmath(x) + exp_negx_cmath(x);
  }
  double *funcs = {*cos, *exp_negx, *cos_and_exp};
}

#endif
