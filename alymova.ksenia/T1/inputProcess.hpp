#ifndef INPUT_PROCESS_HPP
#define INPUT_PROCESS_HPP
#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
namespace alymova
{
  Shape* makeShape(std::istream& in, Shape** shapes);
  Rectangle* makeRectangle(double x1, double y1, double x2, double y2);
  void clear(Shape** shapes);
  void print(std::ostream& out, Shape** shapes);
  void scale(Shape** shapes, point_t s, double ratio);
}
#endif
