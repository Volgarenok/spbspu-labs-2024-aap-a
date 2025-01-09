#include "square.hpp"
#include <stdexcept>
#include "base-types.hpp"

finaev::Square::Square(point_t l, double s) :
  leftDown(l), side(s)
{
  if (s <= 0)
  {
    throw std::logic_error("The figure does not exist!");
  }
}
double finaev::Square::getArea() const
{
  return side * side;
}
finaev::rectangle_t finaev::Square::getFrameRect() const
{
  double x = (side / 2) + leftDown.x;
  double y = (side / 2) + leftDown.y;
  double width = side;
  double height = side;
  rectangle_t a = {{x, y}, width, height};
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
