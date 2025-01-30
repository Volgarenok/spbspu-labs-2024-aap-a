#ifndef SHAPES_TOOLS_H
#define SHAPES_TOOLS_H
#include "shape.hpp"
#include <cctype>
#include <cmath>

namespace timofeev
{
  bool correct_triangle(point_t p1, point_t p2, point_t p3);
  double triangle_area(point_t p1, point_t p2, point_t p3);
  bool is_point_in_triangle(point_t p1, point_t p2, point_t p3, point_t p4);
  point_t cross_point(point_t p1, point_t p2, point_t p3, point_t p4);
  bool is_point_in_quad(point_t p1, point_t p2, point_t p3, point_t p4, point_t pos);
  void shape_delete(Shape** shapes, size_t count);
  void isoscale(Shape** shapes, size_t count, point_t iso_pos, double factor);
  void print_frame_rect(Shape** shapes, size_t count);
  double print_sum_area(Shape** shapes, size_t count);
}
#endif
