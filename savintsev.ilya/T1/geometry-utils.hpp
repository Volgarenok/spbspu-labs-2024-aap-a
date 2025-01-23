#ifndef GEOMETRY_UTILS_HPP
#define GEOMETRY_UTILS_HPP
#include "base-types.hpp"

namespace savintsev
{
  double getLength(point_t lhs, point_t rhs);
  bool isPointInTriangle(point_t t1, point_t t2, point_t t3, point_t p);
  bool findLinesIntersect(point_t m1, point_t m2, point_t n1, point_t n2, point_t & found);
  double getTriangleArea(point_t p1, point_t p2, point_t p3);
  bool isTriangle(point_t p1, point_t p2, point_t p3);
}

#endif
