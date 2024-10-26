#ifndef TAYLOR_HPP
#define TAYLOR_HPP
#include <cstddef>

namespace dribas
{
  double getTaylor(double x,size_t koll,double error);
  double getUno_div_cube(double x);
}
#endif
