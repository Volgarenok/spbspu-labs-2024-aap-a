#ifndef GEOMETRIC_CALCULATIONS_HPP
#define GEOMETRIC_CALCULATIONS_HPP
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace petrov
{
  double calculateDistBtwPoints(const point_t & p1, const point_t & p2);
  void changeCoordinates(point_t ** points, size_t number_of_points, double dx, double dy);
  void changeCoordinatesDueToScaling(point_t ** points, const point_t & pos, size_t number_of_points, double scale_value);
  rectangle_t getFrameRectByOtherShapes(const Shape * const * ptr_shapes, size_t number_of_shapes);
}
#endif
