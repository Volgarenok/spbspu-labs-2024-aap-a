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
  bool findIntersectionPoint(point_t p1, point_t p2, point_t p3, point_t p4, point_t &intersection);
  double calculateTotalArea(Shape **shapeList, size_t shapeCount);
  void outputFrameCoordinates(Shape **shapeList, size_t shapeCount);
  void applyIsoScaling(Shape **shapeList, size_t shapeCount, point_t isoCenter, double scaleFactor);
  void deleteShapes(Shape **shapeList, size_t shapeCount);
}

#endif
