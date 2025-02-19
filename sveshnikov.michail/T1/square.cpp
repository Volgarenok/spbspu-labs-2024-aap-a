#include "square.hpp"
#include <cmath>
#include <stdexcept>

sveshnikov::Square::Square(point_t low_left, double side):
  low_left_(low_left),
  side_(side)
{
  if (side <= 0)
  {
    throw std::logic_error("ERROR: incorrect side value of square");
  }
}

double sveshnikov::Square::getArea() const
{
  return side_ * side_;
}

sveshnikov::rectangle_t sveshnikov::Square::getFrameRect() const
{
  point_t center = {low_left_.x + (side_ / 2), low_left_.y + (side_ / 2)};
  return {side_, side_, center};
}

void sveshnikov::Square::move(const point_t p)
{
  move(p.x - getFrameRect().pos.x, p.y - getFrameRect().pos.y);
}

void sveshnikov::Square::move(double dx, double dy)
{
  low_left_ = movePoint(low_left_, dx, dy);
}

void sveshnikov::Square::unsafeScale(double k)
{
  point_t ctr = getFrameRect().pos;
  low_left_ = scalingMovePoint(low_left_, ctr, k);
  side_ *= k;
}

sveshnikov::Shape *sveshnikov::Square::clone() const
{
  return new Square(low_left_, side_);
}
