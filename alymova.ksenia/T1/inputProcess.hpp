#ifndef INPUT_PROCESS_HPP
#define INPUT_PROCESS_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
#include "composite-shape.hpp"
namespace alymova
{
  void makeShape(std::istream& in, CompositeShape& shapes, bool& wrong_shape_flag, double* scale_params);
  void print(std::ostream& out, const Shape* shape);
  void print(std::ostream& out, const CompositeShape& shapes);
}
#endif
