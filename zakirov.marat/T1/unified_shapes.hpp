#ifndef UNIFIED_SHAPES_HPP
#define UNIFIED_SHAPES_HPP
#include <istream>
#include <ostream>
#include "shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "ring.hpp"
#include "polygon.hpp"
#include "composite-shape.hpp"

namespace zakirov
{
  Shape * make_shape(double * data);
  Rectangle * make_rectangle(double bottom_x, double bottom_y, double top_x, double top_y);
  Circle * make_circle(double center_x, double center_y, double radius);
  Ring * make_ring(double center_x, double center_y, double in_radius, double ex_radius);
  Polygon * make_polygon(size_t points_num, point_t & points);
  double * get_data(std::istream & in);
  double get_total_area(Shape ** shapes, size_t size);
  void output_frame(std::ostream & out, CompositeShape & shapes);
  void full_output(std::ostream & out, CompositeShape & shapes);
  void clear_shapes(Shape ** shapes, size_t quantity);
  void check_scale_full_composition(CompositeShape & shapes, const point_t & target, double k);
  void scale_element(Shape * shape, const point_t & target, double k);
  void scale_full_composition(CompositeShape & shapes, const point_t & target, double k);
}

#endif
