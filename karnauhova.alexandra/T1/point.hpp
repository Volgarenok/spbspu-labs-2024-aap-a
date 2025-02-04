#ifndef POINT_HPP
#define POINT_HPP
#include <cstddef>
#include "shape.hpp"
namespace karnauhova
{
  double getDistance(point_t a, point_t b);
  bool isEqual(point_t a, point_t b);
  rectangle_t frameRect(Shape** shapes, size_t count);
}
#endif
