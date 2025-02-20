#ifndef MAKE_SHAPES_HPP
#define MAKE_SHAPES_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "circle.hpp"
#include "square.hpp"

namespace komarova
{
  void make_shapes(std::istream& input, Shape** shapes, bool& wrong_shape, size_t& count, double& x_sc, double& y_sc, double& coef);
  void area_sum(std::ostream& output, Shape** shapes);
  void scale(Shape** shapes, point_t point, double coef);
  void frame_rect_xy(std::ostream& output, Shape** shapes);
  void delete_shapes(Shape** shapes);
}

#endif
