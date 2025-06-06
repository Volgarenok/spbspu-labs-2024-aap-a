#ifndef TRIANGLEOPERATIONS_HPP
#define TRIANGLEOPERATIONS_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace lebedev
{
  double triangleArea(point_t p1, point_t p2, point_t p3);
  bool isTriangle(point_t p1, point_t p2, point_t p3);
  bool isPointInsideTriangle(point_t p1, point_t p2, point_t p3, point_t p4);
}
#endif
