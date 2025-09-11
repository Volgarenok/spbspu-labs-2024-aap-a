#ifndef IOOPERATIONS_HPP
#define IOOPERATIONS_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <iostream>

namespace shabalin
{
  void inputScale(const char *string, point_t &point, double &k);
  char *input(std::istream &input);
  void shapeOutput(std::ostream &output, const Shape *const *shapes, size_t shapesCount);
}
#endif
