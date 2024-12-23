#ifndef CREATE_SHAPE_HPP
#define CREATE_SHAPE_HPP
#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "ring.hpp"
#include "regular.hpp"

namespace balashov
{
  Rectangle* makeRectangle(std::istream& in);
  Ring* makeRing(std::istream& in);
  Regular* makeRegular(std::istream& in);
  Circle* makeCircle(std::istream& in);
  void deleteShapes(Shape** shapes, size_t count);
}

#endif
