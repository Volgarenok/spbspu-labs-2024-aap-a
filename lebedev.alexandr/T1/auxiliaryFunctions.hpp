#ifndef AUXILIARYFUNCTIONS_HPP
#define AUXILIARYFUNCTIONS_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace lebedev
{
  double max(double a, double b, double c);
  double min(double a, double b, double c);
  double triangleArea(point_t p1, point_t p2, point_t p3);
  bool isTriangle(point_t p1, point_t p2, point_t p3);
  bool isPointInsideTriangle(point_t p1, point_t p2, point_t p3, point_t p4);
  void deleteShapePtr(Shape** shps, size_t count);
}
#endif
