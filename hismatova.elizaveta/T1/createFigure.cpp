#include "createFigure.hpp"
#include <iostream>

hismatova::rectangle* hismatova::createRectangle(std::istream& in)
{
  double left_x = 0, left_y = 0, right_x = 0, right_y = 0;
  in >> left_x >> left_y >> right_x >> right_y;
  if (left_y >= right_y || left_x >= right_x)
  {
    throw std::wrong_arg("rectangle cannot be built");
  }
  rectangle* rectangle_ = new rectangle(left_x, left_y, right_x, right_y);
  return rectangle_;
}
hismatova::triangle* hismatova::createTriangle(std::istream& in)
{
  point_t p1, p2, p3;
  in >> p1 >> p2 >> p3;
  if ((p1.x == p2.x && p1.y == p2.y) || (p1.x == p3.x && p1.y == p3.y) || (p3.x == p2.x && p3.y == p2.y))
  {
    throw std::wrong_arg("triangle cannot be built");
  }
  triangle* triangle_ = new triangle(p1, p2, p3);
  return triangle_;
}
hismatova::concave* hismatova::createConcave(std::istream& in)
{
  point_t p1, p2, p3, p4;
  in >> p1 >> p2 >> p3 >> p4;
  concave* concave_ = new concave(p1, p2, p3, p4);
  return concave_;
}
