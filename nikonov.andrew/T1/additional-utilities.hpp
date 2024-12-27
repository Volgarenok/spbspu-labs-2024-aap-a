#ifndef ADDITIONAL_UTILITIES_HPP
#define ADDITIONAL_UTILITIES_HPP
#include <cstdlib>
#include <iostream>
#include "shape.hpp"
namespace nikonov
{
  void fillShapeCollection(std::istream &input, Shape *collection[], size_t &cnt, size_t &noncorrect);
  void destoy(Shape *collection[], size_t &cnt);
  void ispScale(Shape *shp, double x, double y, double k);
  bool processCollection(Shape *collection[], size_t cnt);
}
#endif
