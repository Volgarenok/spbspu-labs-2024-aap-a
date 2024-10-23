#ifndef UNO_DIV_CUBE_H
#define UNO_DIV_CUBE_H

#include <cstddef>

namespace mozhegova
{
  double uno_div_cube(double x, size_t k, double error);
  double uno_div_cube_cmath(double x);
}
#endif