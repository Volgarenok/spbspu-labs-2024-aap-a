#include "square.hpp"
#include <stdexcept>

finaev::Square::Square(point_t l, double s) :
  leftDown(l), side(s)
{
}
double finaev::Square::getArea() const
{
  return side*side;
}
finaev::rectangle_t finaev::Square::getFrameRect() const
{
  point_t b;
  b.x = (side / 2) + leftDown.x;
  b.y = (side / 2) + leftDown.y;
  rectangle_t a;
  a.pos = b;
  a.wedth = side;
  a.height = side;
  return a;
}
void finaev::Square::move(point_t a)
{
  leftDown.x = a.x - (side / 2);
  leftDown.y = a.y - (side / 2);
}
void finaev::Square::move(double sx, double sy)
{
  leftDown.x += sx;
  leftDown.y += sy;
}
void finaev::Square::scale(double k)
{
  leftDown.x -= (side * k - side)/2;
  leftDown.y -= (side * k - side)/2;
  side *= k;
}
