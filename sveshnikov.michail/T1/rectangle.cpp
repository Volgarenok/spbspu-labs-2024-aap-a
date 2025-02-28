#include "rectangle.hpp"
#include <stdexcept>

sveshnikov::Rectangle::Rectangle(point_t low_left, point_t up_right):
  low_left_(low_left),
  up_right_(up_right)
{
  if (low_left_.x >= up_right_.x || low_left_.y >= up_right_.y)
  {
    throw std::logic_error("ERROR: incorrect coordinates of rectangle points");
  }
}

double sveshnikov::Rectangle::getArea() const
{
  return (up_right_.x - low_left_.x) * (up_right_.y - low_left_.y);
}

sveshnikov::rectangle_t sveshnikov::Rectangle::getFrameRect() const
{
  double width = up_right_.x - low_left_.x;
  double height = up_right_.y - low_left_.y;
  double x = (low_left_.x + up_right_.x) / 2.0;
  double y = (low_left_.y + up_right_.y) / 2.0;
  return {width, height, {x, y}};
}

void sveshnikov::Rectangle::move(const point_t p)
{
  point_t ctr = getFrameRect().pos;
  move(p.x - ctr.x, p.y - ctr.y);
}

void sveshnikov::Rectangle::move(double dx, double dy)
{
  up_right_ = movePoint(up_right_, dx, dy);
  low_left_ = movePoint(low_left_, dx, dy);
}

void sveshnikov::Rectangle::unsafeScale(double k)
{
  const point_t center = getFrameRect().pos;
  up_right_ = scalingMovePoint(up_right_, center, k);
  low_left_ = scalingMovePoint(low_left_, center, k);
}

sveshnikov::Shape *sveshnikov::Rectangle::clone() const
{
  return new Rectangle(low_left_, up_right_);
}
