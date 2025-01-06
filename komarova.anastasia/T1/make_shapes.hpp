#ifndef MAKE_SHAPES_HPP
#define MAKE_SHAPES_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace komarova
{
  void make_shapes(std::istream& input, Shape** shapes, int& count, bool& wrong_shape, double& x_sc, double& y_sc, double& coef);
  void area_sum(std::ostream& output, Shape** shapes);
  void frame_rect_xy(std::ostream& output, Shape** shapes);
  void delete_shapes(Shape** shapes);
}

#endif
