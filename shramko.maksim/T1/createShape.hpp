#ifndef CREATESHAPE_HPP
#define CREATESHAPE_HPP

#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace shramko
{
  int createShape(std::istream& in, std::ostream& err, std::ostream& out, Shape** shapes);
  void clear(Shape** shapes, size_t count);
  double getArea(Shape** shapes, size_t count);
  void scaling(Shape** shapes, size_t count, point_t centre, double k);
}

#endif
