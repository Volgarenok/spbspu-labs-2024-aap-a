#ifndef MAKE_SHAPES_HPP
#define MAKE_SHAPES_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace komarova
{
  void makeShapes(std::istream& input, Shape** shapes, bool& wrong_shape, size_t& count, double& x_sc, double& y_sc, double& coef);
  void sumArea(std::ostream& output, Shape** shapes);
  void scale(Shape** shapes, point_t point, double coef);
  void unsafeScale(Shape** shapes, point_t point, double coef);
  void getFramerectXY(std::ostream& output, Shape** shapes);
  void deleteShapes(Shape** shapes);
}

#endif
