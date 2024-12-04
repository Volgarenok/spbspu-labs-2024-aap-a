#include "rectangle.hpp"
#include "base_types.hpp"
#include <cmath>

double demehin::Rectangle::getArea() const
{
  double len_h = std::sqrt((rt_.y_ - lb_.y_) * (rt_.y_ - lb_.y_));
  double len_w = std::sqrt((rt_.x_ - lb_.x_) * (rt_.x_ - lb_.x_));
  return len_h * len_w;
}

demehin::rectangle_t demehin::Rectangle::getFrameRect() const
{
  double diag_x = rt_.x_ - lb_.x_;
  double diag_y = rt_.y_ - lb_.y_;
  rectangle_t frame_rect;
  frame_rect.pos_.x_ = diag_x / 2;
  frame_rect.pos_.y_ = diag_y / 2;
  frame_rect.height_ = std::sqrt((rt_.y_ - lb_.y_) * (rt_.y_ - lb_.y_));
  frame_rect.width_ = std::sqrt((rt_.x_ - lb_.x_) * (rt_.x_ - lb_.x_));
  return frame_rect;
}

void demehin::Rectangle::move(point_t s)
{
  double diag_x = rt_.x_ - lb_.x_;
  double diag_y = rt_.y_ - lb_.y_;
  point_t centre;
  centre.x_ = diag_x / 2;
  centre.y_ = diag_y / 2;
  double difference_x = s.x_ - centre.x_;
  double difference_y = s.y_ - centre.y_;
  rt_.x_ += difference_x;
  rt_.y_ += difference_y;
  lb_.x_ += difference_x;
  lb_.y_ += difference_y;
}

void demehin::Rectangle::move(double x, double y)
{
  rt_.x_ += x;
  rt_.y_ += y;
  lb_.x_ += x;
  lb_.y_ += y;
}

void demehin::Rectangle::scale(double k)
{
  point_t centre = getFrameRect().pos_;
  lb_.x_ = (lb_.x_ - centre.x_) * k + centre.x_;
  lb_.y_ = (lb_.y_ - centre.y_) * k + centre.y_;
  rt_.x_ = (rt_.x_ - centre.x_) * k + centre.x_;
  rt_.y_ = (rt_.y_ - centre.y_) * k + centre.y_;
}
