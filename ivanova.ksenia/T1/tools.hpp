#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <fstream>
#include "rectangle.hpp"
#include "concave.hpp"

namespace ivanova
{
  bool areSegmentsIntersecting(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4);
  double vectorLength(point_t a, point_t b);
  void deleteShapes(Shape** shps, const size_t size);
  double getSumArea(Shape **shp, size_t size);
  void printFrameRect(Shape** shps, size_t size);
  void scale(Shape** shps, size_t size, point_t scalePoint, double k);
  point_t getIntersection(point_t A, point_t B, point_t C, point_t D);
  bool operator==(const ivanova::point_t a, const ivanova::point_t b);
}

#endif
