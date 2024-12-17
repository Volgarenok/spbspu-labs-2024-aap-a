#ifndef INPUT_PROCESS_HPP
#define INPUT_PROCESS_HPP
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
namespace alymova
{
  void makeShape(std::istream& in, Shape** shapes, int& shapes_now, bool& wrong_shape_flag,
    double& scale_x, double& scale_y, double& scale_ratio);
  void print(std::ostream& out, Shape** shapes);
  void clear(Shape** shapes);
}
#endif
