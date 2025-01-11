#ifndef INPUT_PROCESS_HPP
#define INPUT_PROCESS_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
namespace alymova
{
  void makeShape(std::istream& in, Shape** shapes, size_t& shapes_now, bool& wrong_shape_flag,
    double& scale_x, double& scale_y, double& scale_ratio);
  Shape* makeRectangle(std::istream& in);
  void readParameters(std::istream& in, double* params, size_t size);
  void print(std::ostream& out, const Shape* const* shapes, size_t size);
  void clear(Shape** shapes);
}
#endif
