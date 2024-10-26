#ifndef TAYLOSERIES_HPP
#define TAYLORSERIES_HPP
#include <cmath>
#include <iostream>
#include <iomanip>
namespace maslov
{
  double fromCMath(double x);
  double fromTaylor(double x, size_t k, double error);
  void outString(double x, size_t k, double error);
  void outTable(double left, double right,
  size_t k, double error, double step);
}
#endif