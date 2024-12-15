#include "makeObjects.hpp"
#include <cmath>

namespace finaev
{
  bool operator ==(const finaev::point_t a, const finaev::point_t b);
}

double finaev::len(point_t a, point_t b)
{
  return std::sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}
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
bool finaev::operator ==(const finaev::point_t a, const finaev::point_t b)
{
        return ((a.x == b.x) && (a.y == b.y));
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
  if (first == second || first == third || first == internal || second == third || second == internal || third == internal)
  {
    return nullptr;
  }
  if (len(first, second) + len(first, third) <= len(second, third))
  {
    return nullptr;
  }
  else if (len(second, third) + len(first, third) <= len(first, second))
  {
    return nullptr;
  }
  else if (len(first, second) + len(second, third) <= len(first, third))
  {
    return nullptr;
  }
  Concave* concave = new Concave(first, second, third, internal);
  return concave;
}
