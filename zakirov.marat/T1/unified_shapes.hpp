#ifndef UNIFIED_SHAPES_HPP
#define UNIFIED_SHAPES_HPP
#include "shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ring.hpp"

namespace zakirov
{
  Shape * make_shape(const double * data);
  Rectangle * make_rectangle(double bottom_x, double bottom_y, double top_x, double top_y);
  Circle * make_circle(double center_x, double center_y, double radius);
  Ring * make_ring(double center_x, double center_y, double in_radius, double ex_radius);
  double * get_data(char * line);
  void scale_from_point(Shape * mutable_shape, point_t target, double k);
}

#endif
