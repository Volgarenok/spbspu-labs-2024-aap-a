#include "rectangle.hpp"
#include <cmath>

double hismatova::rectangle::getArea() const
{
  return std::sqrt((right_.y - left_.y) * (right_.y - left_.y)) * std::sqrt((right_.x - left_.x) * (right_.x - left_.x));
}
double hismatova::rectangle::rectangle(double left_x, double left_y, double right_x, double right_y):
  left_.x(left_x),
  left_.y(left_y),
  right_.x(right_x),
  right_.y(right_y)
{}
void hismatova::rectangle::move(double x, double y)
{
  right_.x += x;
  left_.x += x;
  right_.y += y;
  left_.y += y;
}
void hismatova::rectangle::move(point_t point)
{
  point_t center;
  center.x = right_.x - (right_.x - left_.x) / 2;
  center.y = right_.y - (right_.y - left_.y) / 2;
  right_.x += point.x - center.x;
  right_.y += point.y - center.y;
  left_.x += point.x - center.x;
  left_.x += point.y - center.y;
}
hismatova::rectangle_t hismatova::rectangle::getFrameRect() const
{
  rectangle FrameRect;
  FrameRect.pos.x = left_.x + (right_.x - left_.x) / 2;
  FrameRect.pos.y = left_.y + (right_.y - left_.y) / 2;
  FrameRect.height = right_.y - left_.y;
  FrameRect.width = right_.x - left_.x;
  return FrameRect;
}
void hismatova::rectangle::scale(double index)
{
  if (index <= 0)
  {
    std::cerr << "index must be positive";
    return;
  }
  point_t center = getFrameRect().pos;
  left_.x = center.x + index * (left_.x - center.x);
  left_.y = center.y + index * (left_.y - center.y);
  right_.x = center.x + index * (right_.x - center.x);
  right_.y = center.y + index * (right_.y - center.y);
}
