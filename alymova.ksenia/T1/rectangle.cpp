#include "rectangle.hpp"
#include <stdexcept>
alymova::Rectangle::Rectangle(point_t p1, point_t p2):
  low_left_(),
  upp_right_(),
  width_(0),
  height_(0),
  pos_(),
  frame_rect_()
{
  if (p1 < p2)
  {
    low_left_ = p1;
    upp_right_ = p2;
  }
  else
  {
    low_left_ = p2;
    upp_right_ = p1;
  }
  width_ = upp_right_.getX() - low_left_.getX();
  height_ = upp_right_.getY() - low_left_.getY();
  pos_ = point_t((low_left_.getX() + width_ / 2), (upp_right_.getY() - height_ / 2));
  frame_rect_ = rectangle_t(low_left_, upp_right_);
}
double alymova::Rectangle::getArea() const
{
  return width_ * height_;
}
alymova::rectangle_t alymova::Rectangle::getFrameRect() const
{
  return frame_rect_;
}
void alymova::Rectangle::move(double shift_x, double shift_y)
{
  point_t shift_point(shift_x, shift_y);
  pos_ += shift_point;
  low_left_ += shift_point;
  upp_right_ += shift_point;
  frame_rect_.move(shift_x, shift_y);
}
void alymova::Rectangle::move(point_t point)
{
  double shift_x = point.getX() - pos_.getX();
  double shift_y = point.getY() - pos_.getY();
  move(shift_x, shift_y);
}
void alymova::Rectangle::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("The scale ratio should be positive");
  }
  if (ratio == 1)
  {
    return;
  }
  low_left_ += (point_t(0.5 * (width_ - ratio * width_), 0.5 * (height_ - ratio * height_)));
  upp_right_ += (point_t(0.5 * (ratio * width_ - width_), 0.5 * (ratio * height_ - height_)));
  width_ *= ratio;
  height_ *= ratio;
  frame_rect_.scale(ratio);
}
