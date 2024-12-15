#ifndef GEOM_FUN_HPP
#define GEOM_FUN_HPP
#include "shape.hpp"
#include <cctype>
#include <cmath>

namespace maslovskiy
{
  bool isCorrectTriangle(point_t vertexA, point_t vertexB, point_t vertexC);
  double calculateTriangleArea(point_t vertexA, point_t vertexB, point_t vertexC);
  bool isPointInTriangle(point_t vertexA, point_t vertexB, point_t vertexC, point_t point);
  bool isPointInQuad(point_t vertexA, point_t vertexB, point_t vertexC, point_t vertexD, point_t pos);
  point_t findIntersectionPoint(point_t vertexA, point_t vertexB, point_t vertexC, point_t vertexD);
}

#endif
