#include "square.hpp"
#include <cmath>

sveshnikov::Square::Square(point_t low_left, double side):
  low_left_(low_left),
  side_(side)
{}

double sveshnikov::Square::getArea() const
{
  return side_ * side_;
}

sveshnikov::rectangle_t sveshnikov::Square::getFrameRect() const
{
  point_t center = {low_left_.x + (side_ / 2), low_left_.y + (side_ / 2)};
  return {side_, side_, center};
}

void sveshnikov::Square::move(point_t p)
{
  double ctr_x = getFrameRect().pos.x, ctr_y = getFrameRect().pos.y;
  low_left_.x += p.x - ctr_x;
  low_left_.y += p.y - ctr_y;
}

void sveshnikov::Square::move(double dx, double dy)
{
  low_left_.x += dx;
  low_left_.y += dy;
}

void sveshnikov::Square::scale(double k)
{
  double ctr_x = getFrameRect().pos.x, ctr_y = getFrameRect().pos.y;
  low_left_.x = ctr_x - k * (ctr_x - low_left_.x);
  low_left_.y = ctr_y - k * (ctr_y - low_left_.y);
  side_ *= k;
}
