#ifndef IOOPERATIONS_HPP
#define IOOPERATIONS_HPP
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"

namespace shabalin
{
  void inputScale(const char *string, point_t &point, double &k);
  void shapeOutput(std::ostream &output, const Shape *const *shapes, size_t shapesCount);
}
#endif
