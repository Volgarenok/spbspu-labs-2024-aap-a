#ifndef SHAPES_PROCESS_HPP
#define SHAPES_PROCESS_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace alymova
{
  void scale(Shape** shapes, point_t s, double ratio);
  bool getRectanglurTriangle(point_t p1, point_t& p2, point_t& p3);
  double getVector(point_t p1, point_t p2);
}
#endif
