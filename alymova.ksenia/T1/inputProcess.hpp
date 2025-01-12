#ifndef INPUT_PROCESS_HPP
#define INPUT_PROCESS_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
#include "composite-shape.hpp"
namespace alymova
{
  void makeShape(std::istream& in, CompositeShape& shapes, bool& wrong_shape_flag, double* scale_params);
  Shape* makeRectangle(std::istream& in);
  Shape* makeCircle(std::istream& in);
  Shape* makeRegular(std::istream& in);
  void readParameters(std::istream& in, double* params, size_t size);
  void print(std::ostream& out, Shape* shape);
  void print(std::ostream& out, CompositeShape shapes);
  void clear(Shape** shapes);
}
#endif
