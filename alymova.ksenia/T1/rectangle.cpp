#include "rectangle.hpp"
#include <stdexcept>
alymova::Rectangle::Rectangle(point_t p1, point_t p2):
  low_left_(),
  upp_right_(),
  width(0),
  height(0),
  pos(),
  frame_rect_()
{
  if (p2 < p1)
  {
    throw std::logic_error("First point should be more left and low than other");
  }
  low_left_ = p1;
  upp_right_ = p2;
  width = upp_right_.getX() - low_left_.getX();
  height = upp_right_.getY() - low_left_.getY();
  pos = point_t((low_left_.getX() + width / 2), (upp_right_.getY() - height / 2));
  frame_rect_ = rectangle_t(low_left_, upp_right_);
}
double alymova::Rectangle::getArea() const
{
  return width * height;
}
alymova::rectangle_t alymova::Rectangle::getFrameRect() const
{
  return frame_rect_;
}
void alymova::Rectangle::move(double shift_x, double shift_y)
{
  point_t shift_point(shift_x, shift_y);
  pos += shift_point;
  low_left_ += shift_point;
  upp_right_ += shift_point;
  frame_rect_.move(shift_x, shift_y);
}
void alymova::Rectangle::move(point_t point)
{
  double shift_x = point.getX() - pos.getX();
  double shift_y = point.getY() - pos.getY();
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
  low_left_ += (point_t(0.5 * (width - ratio * width), 0.5 * (height - ratio * height)));
  upp_right_ += (point_t(0.5 * (ratio * width - width), 0.5 * (ratio * height - height)));
  width *= ratio;
  height *= ratio;
  frame_rect_.scale(ratio);
}
