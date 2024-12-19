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
  frame.height = up_right_.y - low_left_.y;
  frame.width = up_right_.x - low_left_.x;
  frame.pos.x = (low_left_.x + up_right_.x) / 2;
  frame.pos.y = (low_left_.y + up_right_.y) / 2;
  return frame;
}

void sveshnikov::Rectangle::move(point_t p)
{
  up_right_.x = p.x + (up_right_.x - low_left_.x) / 2;
  up_right_.y = p.y + (up_right_.y - low_left_.y) / 2;
  low_left_.x = p.x - (up_right_.x - low_left_.x) / 2;
  low_left_.y = p.y - (up_right_.y - low_left_.y) / 2;
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
  double height = up_right_.y - low_left_.y;
  double width = up_right_.x - low_left_.x;
  up_right_.x += width * (k - 1) / 2;
  up_right_.y += height * (k - 1) / 2;
  low_left_.x -= width * (k - 1) / 2;
  low_left_.y -= height * (k - 1) / 2;
}
