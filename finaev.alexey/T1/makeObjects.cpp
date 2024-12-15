#include "makeObjects.hpp"

finaev::Rectangle* finaev::makeRectangle(std::istream& in)
{
  double x0 = 0, y0 = 0, x1 = 0, y1 = 0;
  in >> x0 >> y0 >> x1 >> y1;
  if (x0 >= x1 || y0 >= y1)
  {
    return nullptr;
  }
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
