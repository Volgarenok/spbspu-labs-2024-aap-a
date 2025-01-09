#include "makeShapes.hpp"
#include <cmath>

finaev::Rectangle* finaev::makeRectangle(std::istream& in)
{
  double x0 = 0, y0 = 0, x1 = 0, y1 = 0;
  in >> x0 >> y0 >> x1 >> y1;
  point_t l, r;
  l.x = x0;
  l.y = y0;
  r.x = x1;
  r.y = y1;
  Rectangle* rectangle = new Rectangle(l, r);
  return rectangle;
}

finaev::Square* finaev::makeSquare(std::istream& in)
{
  double x0, y0, side;
  in >> x0 >> y0 >> side;
  if (side <= 0)
  {
    return nullptr;
  }
  point_t l;
  l.x = x0;
  l.y = y0;
  Square* square = new Square(l, side);
  return square;
}

finaev::Concave* finaev::makeConcave(std::istream& in)
{
  double x1, y1, x2, y2, x3, y3, x4, y4;
  in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  point_t first, second, third, internal;
  first = {x1, y1};
  second = {x2, y2};
  third = {x3, y3};
  internal = {x4, y4};
  Concave* concave = new Concave(first, second, third, internal);
  return concave;
}

finaev::Shape* finaev::makeShapes(std::istream& in, std::string str)
{
  if (str == "RECTANGLE")
  {
    return makeRectangle(in);
  }
  else if (str == "SQUARE")
  {
    return makeSquare(in);
  }
  else if (str == "CONCAVE")
  {
    return makeConcave(in);
  }
  return nullptr;
}
