#include "regular.hpp"
#include <cmath>
#include <stdexcept>
#include <limits>
#include "shapesProcess.hpp"
constexpr double PI = std::acos(-1.0);
constexpr double inaccuracy = 0.0000000001;
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
    throw std::logic_error("Incorrect description regular");
  }
  pos_ = pos;
  top_ = top;
  other_ = other;
  radius_big_ = getVector(pos_, top_);
  radius_small_ = getVector(pos_, other_);
  other_side_ = getVector(top_, other_);
  sides_cnt_ = getCntSides();
  if (sides_cnt_ == 0 || sides_cnt_ < 3)
  {
    throw std::logic_error("Incorrect description regular");
  }
  frame_rect_ = setFrameRect();
}
double alymova::Regular::getArea() const
{
  //return 0.5 * radius_big_ * radius_big_ * sides_cnt_ * std::sin((360 / getCntSides()) * PI / 180);
  return 0.5 * radius_small_ * other_side_ * sides_cnt_ * 2.0;
}
size_t alymova::Regular::getCntSides() const
{
  double sides = PI / (std::acos(radius_small_ / radius_big_));
  size_t round_sides = std::round(sides);
  if (std::abs((std::cos(180 / std::round(sides) * PI / 180)) - (radius_small_ / radius_big_)) < inaccuracy)
  {
    return round_sides;
  }
  return 0;
}
alymova::rectangle_t alymova::Regular::getFrameRect() const
{
  return frame_rect_;
}
alymova::rectangle_t alymova::Regular::setFrameRect()
{
  double low_left_x = std::numeric_limits< double >::max();
  double low_left_y = std::numeric_limits< double >::max();
  double upp_right_x = std::numeric_limits< double >::min();
  double upp_right_y = std::numeric_limits< double >::min();
  double angle_start = std::acos(other_side_ / radius_big_);
  if (top_.y == pos_.y)
  {
    angle_start = 0;
  }
  for (size_t i = 0; i < sides_cnt_; i++)
  {
    double angle_now = angle_start + i * 2 * PI / sides_cnt_;
    low_left_x = std::min(low_left_x, pos_.x + radius_big_ * std::cos(angle_now));
    low_left_y = std::min(low_left_y, pos_.y + radius_big_ * std::sin(angle_now));
    upp_right_x = std::max(upp_right_x, pos_.x + radius_big_ * std::cos(angle_now));
    upp_right_y = std::max(upp_right_y, pos_.y + radius_big_ * std::sin(angle_now));
  }
  point_t p1 = {low_left_x, low_left_y};
  point_t p2 = {upp_right_x, upp_right_y};
  return rectangle_t(p1, p2);
}
void alymova::Regular::move(double shift_x, double shift_y)
{
  point_t shift_point{shift_x, shift_y};
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
  radius_big_ *= ratio;
  radius_small_ *= ratio;
  other_side_ *= ratio;
  frame_rect_.scale(ratio);
}
alymova::Shape* alymova::Regular::clone() const
{
  Regular* reg = nullptr;
  try
  {
    reg = new Regular(pos_, top_, other_);
    Shape* shape = reg;
    return shape;
  }
  catch (const std::bad_alloc& e)
  {
    delete reg;
    throw;
  }
}
