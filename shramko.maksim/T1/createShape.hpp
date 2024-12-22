#ifndef CREATESHAPE_HPP
#define CREATESHAPE_HPP

#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace shramko
{
  int createShape(std::istream& in, std::ostream& err, std::ostream& out, Shape** shape);
  void destroy(Shape** shape, size_t count);
  double getEveryArea(Shape** shape, size_t count);
  void scaling(Shape** shape, size_t count, point_t centre, double k);
}

#endif
