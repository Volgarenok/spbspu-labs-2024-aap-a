#ifndef TAYLORPOLYNOMIAL_HPP
#define TAYLORPOLYNOMIAL_HPP
#include <cstddef>
namespace abramov
{
  double f(double x, size_t k, double error);
  double exp_x(double x);
  void str_of_table(double x, size_t k, double error);
}
#endif
