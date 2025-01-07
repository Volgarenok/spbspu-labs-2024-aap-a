#ifndef MAKE_SHAPES_HPP
#define MAKE_SHAPES_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace komarova
{
  void make_shapes(std::istream& input, Shape** shapes, bool& wrong_shape);
  void area_sum(std::ostream& output, Shape** shapes);
  void scale(Shape** shapes, point_t point, double coef);
  void frame_rect_xy(std::ostream& output, Shape** shapes);
  void delete_shapes(Shape** shapes);
  Rectangle* make_rect(std::istream& input);
  Circle* make_circ(std::istream& input);
  Triangle* make_tri(std::istream& input);
  Square* make_sqr(std::istream& input);
}

#endif
