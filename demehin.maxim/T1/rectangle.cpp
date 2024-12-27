#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

demehin::Rectangle::Rectangle(point_t left_bot, point_t right_top):
  lb_(left_bot),
  rt_(right_top)
{
  if (rt_.x <= lb_.x || rt_.y <= lb_.y)
  {
    throw std::logic_error("incorrect shape");
  }
}

double demehin::Rectangle::getArea() const
{
  double len_h = std::sqrt((rt_.y - lb_.y) * (rt_.y - lb_.y));
  double len_w = std::sqrt((rt_.x - lb_.x) * (rt_.x - lb_.x));
  return len_h * len_w;
}

demehin::rectangle_t demehin::Rectangle::getFrameRect() const
{
  double width = rt_.x - lb_.x;
  double height = rt_.y - lb_.y;
  double pos_x = lb_.x + width / 2.0;
  double pos_y = lb_.y + height / 2.0;
  rectangle_t frame_rect;
  frame_rect.pos.x = pos_x;
  frame_rect.pos.y = pos_y;
  frame_rect.height = height;
  frame_rect.width = width;
  return frame_rect;
}

void demehin::Rectangle::move(point_t s)
{

  double width = rt_.x - lb_.x;
  double height = rt_.y - lb_.y;
  double cent_x = rt_.x - width / 2;
  double cent_y = rt_.y - height / 2;
  point_t centre;
  centre.x = cent_x;
  centre.y = cent_y;
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
