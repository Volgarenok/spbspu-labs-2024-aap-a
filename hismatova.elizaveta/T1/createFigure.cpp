#include "createFigure.hpp"
#include <iostream>

hismatova::rectangle* hismatova::createRectangle(std::istream& in)
{
  double left_x = 0, left_y = 0, right_x = 0, right_y = 0;
  in >> left_x >> left_y >> right_x >> right_y;
  if (left_y >= right_y || left_x >= right_x)
  {
    throw std::invalid_argument("rectangle cannot be built");
  }
  rectangle* rectangle_ = new rectangle({ left_x, left_y }, { right_x, right_y });
  return rectangle_;
}
hismatova::triangle* hismatova::createTriangle(std::istream& in)
{
  double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
  in >> x1 >> y2 >> x2 >> y2 >> x3 >> y3;
  if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x3 == x2 && y3 == y2))
  {
    throw std::invalid_argument("triangle cannot be built");
  }
  triangle* triangle_ = new triangle({ x1, y1 }, { x2, y2 }, { x3, y3 });
  return triangle_;
}
hismatova::concave* hismatova::createConcave(std::istream& in)
{
  double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
  in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  concave* concave_ = new concave( { x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
  return concave_;
}
