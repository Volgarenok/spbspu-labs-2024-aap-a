#include "square.hpp"
#include <stdexcept>
#include "base-types.hpp"

namespace
{
  finaev::Rectangle createSquare(finaev::point_t leftDown, double side)
  {
    finaev::point_t rightUp = { (leftDown.x + side), (leftDown.y + side) };
    return { leftDown, rightUp };
  }
}


finaev::Square::Square(point_t l, double s):
  rect_(createSquare(l, s))
{
  if (s <= 0)
  {
    throw std::invalid_argument("The figure does not exist!");
  }
}
double finaev::Square::getArea() const
{
  return rect_.getArea();
}
finaev::rectangle_t finaev::Square::getFrameRect() const
{
  return rect_.getFrameRect();
}
void finaev::Square::move(point_t a)
{
  rect_.move(a);
}
void finaev::Square::move(double sx, double sy)
{
  rect_.move(sx, sy);
}
void finaev::Square::scale(double k)
{
  rect_.scale(k);
}
