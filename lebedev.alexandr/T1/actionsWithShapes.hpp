#ifndef ACTIONSWITHSHAPES_HPP
#define ACTIONSWITHSHAPES_HPP
#include "shape.hpp"

namespace lebedev
{
  double getSumArea(lebedev::Shape** shps, size_t count);
  void scaleForShapes(lebedev::Shape** shps, size_t count, lebedev::point_t scalePoint, double k);
  void getFrameCoordinates(lebedev::Shape** shps, size_t count);
}
#endif
