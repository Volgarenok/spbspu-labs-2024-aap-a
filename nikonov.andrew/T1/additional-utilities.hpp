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
  void scaleCollection(Shape *collection[], size_t cnt, double x, double y, double k);
  double getCollectionArea(Shape *collection[], size_t cnt);
  void outputCollection(std::ostream &out, Shape *collection[], size_t cnt);
  void processCollection(std::istream &input, Shape *collection[], size_t cnt);
}
#endif
