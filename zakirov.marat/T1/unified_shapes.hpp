#ifndef UNIFIED_SHAPES_HPP
#define UNIFIED_SHAPES_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ring.hpp"
#include "polygon.hpp"

namespace zakirov
{
  Shape * make_shape(const double * data);
  Rectangle * make_rectangle(double bottom_x, double bottom_y, double top_x, double top_y);
  Circle * make_circle(double center_x, double center_y, double radius);
  Ring * make_ring(double center_x, double center_y, double in_radius, double ex_radius);
  Polygon * make_polygon(size_t points_num, point_t * points);
  double * get_data(std::istream & in);
  void scale_from_point(Shape * mutable_shape, point_t target, double k);
  void output_frame(std::ostream & out, Shape ** shapes, size_t quantity);
  void clear_shapes(Shape ** shapes, size_t quantity);
}

#endif
