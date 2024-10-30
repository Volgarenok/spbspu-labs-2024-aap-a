#ifndef TAYLORSERIES_HPP
#define TAYLORSERIES_HPP
#include <cmath>
#include <stdexcept>
namespace smirnov
{
   double sinTaylor(double x, size_t k, double error);
   double sinCmath(double x);
}
#endif
