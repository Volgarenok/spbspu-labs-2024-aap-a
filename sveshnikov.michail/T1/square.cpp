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
  low_left_.x += dx;
  low_left_.y += dy;
}

void sveshnikov::Square::unsafe_scale(double k)
{
  double ctr_x = getFrameRect().pos.x, ctr_y = getFrameRect().pos.y;
  low_left_.x = ctr_x - k * (ctr_x - low_left_.x);
  low_left_.y = ctr_y - k * (ctr_y - low_left_.y);
  side_ *= k;
}

sveshnikov::Shape *sveshnikov::Square::clone() const
{
  return new Square(low_left_, side_);
}
