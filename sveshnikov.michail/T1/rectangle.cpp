#include "rectangle.hpp"

sveshnikov::Rectangle::Rectangle(point_t low_left, point_t up_right):
  low_left_(low_left),
  up_right_(up_right)
{}

double sveshnikov::Rectangle::getArea() const
{
  return (up_right_.x - low_left_.x) * (up_right_.y - low_left_.y);
}

sveshnikov::rectangle_t sveshnikov::Rectangle::getFrameRect() const
{
  rectangle_t frame = {0, 0, {0, 0}};
  frame.width = up_right_.x - low_left_.x;
  frame.height = up_right_.y - low_left_.y;
  frame.pos.x = (low_left_.x + up_right_.x) / 2.0;
  frame.pos.y = (low_left_.y + up_right_.y) / 2.0;
  return frame;
}

void sveshnikov::Rectangle::move(const point_t p)
{
  const point_t ctr = getFrameRect().pos;
  up_right_.x += p.x - ctr.x;
  up_right_.y += p.y - ctr.y;
  low_left_.x += p.x - ctr.x;
  low_left_.y += p.y - ctr.y;
}

void sveshnikov::Rectangle::move(double dx, double dy)
{
  up_right_.x += dx;
  up_right_.y += dy;
  low_left_.x += dx;
  low_left_.y += dy;
}

void sveshnikov::Rectangle::scale(double k)
{
  const point_t ctr = getFrameRect().pos;
  up_right_.x = ctr.x + k * (up_right_.x - ctr.x);
  up_right_.y = ctr.y + k * (up_right_.y - ctr.y);
  low_left_.x = ctr.x - k * (ctr.x - low_left_.x);
  low_left_.y = ctr.y - k * (ctr.y - low_left_.y);
}
