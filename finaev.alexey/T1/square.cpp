#include "square.hpp"
#include <stdexcept>

finaev::Square::Square(point_t l, double s) :
  leftDown(l), side(s)
{
}
double finaev::Square::getArea()
{
  return side*side;
}
finaev::point_t finaev::Square::getCentre()
{
  point_t a;
  a.x = (side / 2) + leftDown.x;
  a.y = (side / 2) + leftDown.y;
  return a;
}
finaev::rectangle_t finaev::Square::getFrameRect()
{
  rectangle_t a;
  a.pos = getCentre();
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
