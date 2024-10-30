#ifndef BREVNOV_HPP
#define BREVNOV_HPP
#include <iostream>
namespace brevnov
{
  double f(const double x, const size_t k, const  double error);
  void outputing(const double left, const double right, const size_t k);
  void tablecheck(double i, const size_t k, const double error);
} 
#endif

