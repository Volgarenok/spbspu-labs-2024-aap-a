#include "rectangle.hpp"
#include <cmath>

demehin::Rectangle::Rectangle(double lbx, double lby, double rtx, double rty)
{
  lb_.x = lbx;
  lb_.y = lby;
  rt_.x = rtx;
  rt_.y = rty;
}

double demehin::Rectangle::getArea() const
{
  double len_h = std::sqrt((rt_.y - lb_.y) * (rt_.y - lb_.y));
  double len_w = std::sqrt((rt_.x - lb_.x) * (rt_.x - lb_.x));
  return len_h * len_w;
}

demehin::rectangle_t demehin::Rectangle::getFrameRect() const
{
  double width = std::abs(rt_.x - lb_.x);
  double height = std::abs(rt_.y - lb_.y);
  rectangle_t frame_rect;
  frame_rect.pos.x = lb_.x + width / 2.0;
  frame_rect.pos.y = lb_.y + height / 2.0;
  frame_rect.height = height;
  frame_rect.width = width;
  return frame_rect;
}

void demehin::Rectangle::move(point_t s)
{

  point_t centre;
  double width = std::sqrt((rt_.y - lb_.y) * (rt_.y - lb_.y));
  double height = std::sqrt((rt_.x - lb_.x) * (rt_.x - lb_.x));
  centre.x = rt_.x - width / 2;
  centre.y = rt_.y - height / 2;
  double difference_x = s.x - centre.x;
  double difference_y = s.y - centre.y;
  rt_.x += difference_x;
  rt_.y += difference_y;
  lb_.x += difference_x;
  lb_.y += difference_y;
}

void demehin::Rectangle::move(double x, double y)
{
  rt_.x += x;
  rt_.y += y;
  lb_.x += x;
  lb_.y += y;
}

void demehin::Rectangle::scale(double k)
{
  point_t centre = getFrameRect().pos;
  lb_.x = (lb_.x - centre.x) * k + centre.x;
  lb_.y = (lb_.y - centre.y) * k + centre.y;
  rt_.x = (rt_.x - centre.x) * k + centre.x;
  rt_.y = (rt_.y - centre.y) * k + centre.y;
}
