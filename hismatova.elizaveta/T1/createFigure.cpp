#include "createFigure.hpp"
#include <iostream>

hismatova::Rectangle* hismatova::createRectangle(std::istream& in)
{
  double left_x = 0, left_y = 0, right_x = 0, right_y = 0;
  in >> left_x >> left_y >> right_x >> right_y;
  if (left_y >= right_y || left_x >= right_x)
  {
    throw std::invalid_argument("rectangle cannot be built");
  }
  Rectangle* rectangle_ = new Rectangle({ left_x, left_y }, { right_x, right_y });
  return rectangle_;
}
hismatova::Triangle* hismatova::createTriangle(std::istream& in)
{
  double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
  in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) <= 0)
  {
    throw std::invalid_argument("triangle cannot be built");
  }
  Triangle* triangle_ = new Triangle({ x1, y1 }, { x2, y2 }, { x3, y3 });
  return triangle_;
}
hismatova::Concave* hismatova::createConcave(std::istream& in)
{
  double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
  in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  double a = 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
  double a1 = 0.5 * std::abs(x4 * (y2 - y3) + x2 * (y3 - y4) + x3 * (y4 - y2));
  double a2 = 0.5 * std::abs(x1 * (y4 - y3) + x4 * (y3 - y1) + x3 * (y1 - y4));
  double a3 = 0.5 * std::abs(x1 * (y2 - y4) + x2 * (y4 - y1) + x4 * (y1 - y2));
  if (a <= 0 || (a != a1 + a2 + a3))
  {
    throw std::invalid_argument("concave cannot be built");
  }
  Concave* concave_ = new Concave( { x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
  return concave_;
}
