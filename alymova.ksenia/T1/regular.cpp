#include "regular.hpp"
#include <cmath>
#include <stdexcept>
#include "shape.hpp"
constexpr double PI = std::acos(-1.0);
alymova::Regular::Regular(point_t pos, point_t top, point_t other):
  pos_(),
  top_(),
  other_(),
  radius_big_(0),
  radius_small_(0),
  other_side_(0),
  sides_cnt_(0),
  frame_rect_()
{
  if (!getRectanglurTriangle(pos, top, other))
  {
    throw std::logic_error("Incorrect points for description regular");
  }
  pos_ = pos;
  top_ = top;
  other_ = other;
  radius_big_ = getVector(pos_, top_);
  radius_small_ = getVector(pos_, other_);
  other_side_ = getVector(top_, other_);
  sides_cnt_ = getCntSides();
  frame_rect_ = setFrameRect();
}
double alymova::Regular::getArea() const
{
  return 0.5 * radius_big_ * radius_big_ * sides_cnt_ * std::sin((360 / getCntSides()) * PI / 180);
}
int alymova::Regular::getCntSides() const
{
  double sides = PI / (std::acos(radius_small_ / radius_big_));
  return std::round(sides);
}
alymova::rectangle_t alymova::Regular::getFrameRect() const
{
  return frame_rect_;
}
alymova::rectangle_t alymova::Regular::setFrameRect()
{
  double low_left_x = 1000, low_left_y = 1000, upp_right_x = -1000, upp_right_y = -1000;
  double angle = PI / sides_cnt_;
  for (size_t i = 0; i < sides_cnt_; i++)
  {
    angle *= i;
    low_left_x = std::min(low_left_x, pos_.x + radius_big_ * std::cos(angle));
    low_left_y = std::min(low_left_y, pos_.y + radius_big_ * std::sin(angle));
    upp_right_x = std::max(upp_right_x, pos_.x + radius_big_ * std::cos(angle));
    upp_right_y = std::max(upp_right_y, pos_.y + radius_big_ * std::sin(angle));
  }
  return rectangle_t(point_t(low_left_x, low_left_y), point_t(upp_right_y, upp_right_y));
}
void alymova::Regular::move(double shift_x, double shift_y)
{
  point_t shift_point(shift_x, shift_y);
  pos_ += shift_point;
  top_ += shift_point;
  other_ += shift_point;
  frame_rect_.move(shift_x, shift_y);
}
void alymova::Regular::move(point_t point)
{
  double shift_x = point.x - pos_.x;
  double shift_y = point.y - pos_.y;
  move(shift_x, shift_y);
}
void alymova::Regular::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("The scale ratio should be positive");
  }
  if (ratio == 1)
  {
    return;
  }
  top_.x = pos_.x + (top_.x - pos_.x) * ratio;
  top_.y = pos_.y + (top_.y - pos_.y) * ratio;
  other_.x = pos_.x + (other_.x - pos_.x) * ratio;
  other_.y = pos_.y + (other_.y - pos_.y) * ratio; 
  frame_rect_.scale(ratio);
}
