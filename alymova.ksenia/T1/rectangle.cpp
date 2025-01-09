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
  if (p2 < p1)
  {
    throw std::logic_error("Incorrect description rectangle");
  }
  low_left_ = p1;
  upp_right_ = p2;
  width_ = upp_right_.x - low_left_.x;
  height_ = upp_right_.y - low_left_.y;
  pos_ = point_t{ (low_left_.x + width_ / 2), (upp_right_.y - height_ / 2) };
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
  point_t shift_point{shift_x, shift_y};
  pos_ += shift_point;
  low_left_ += shift_point;
  upp_right_ += shift_point;
  frame_rect_.move(shift_x, shift_y);
}
void alymova::Rectangle::move(point_t point)
{
  double shift_x = point.x - pos_.x;
  double shift_y = point.y - pos_.y;
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
  low_left_ += (point_t{0.5 * (width_ - ratio * width_), 0.5 * (height_ - ratio * height_)});
  upp_right_ += (point_t{0.5 * (ratio * width_ - width_), 0.5 * (ratio * height_ - height_)});
  width_ *= ratio;
  height_ *= ratio;
  frame_rect_.scale(ratio);
}
alymova::Shape* alymova::Rectangle::clone() const
{
  Rectangle* rect = nullptr;
  try
  {
    rect = new Rectangle(low_left_, upp_right_);
    Shape* shape = rect;
    return shape;
  }
  catch (const std::bad_alloc& e)
  {
    delete rect;
    throw;
  }
}
