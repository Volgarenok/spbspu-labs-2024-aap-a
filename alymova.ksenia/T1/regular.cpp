#include "regular.hpp"
#include <cmath>
#include <stdexcept>
#include <limits>
double PI = std::acos(-1.0);
double inaccuracy = 0.0000000001;
alymova::Regular::Regular(point_t pos, point_t top, point_t other):
  pos_(pos),
  top_(top),
  other_(other),
  sides_cnt_(0),
  frame_rect_()
{
  if (!isRectanglurTriangle(pos, top, other))
  {
    if (!isRectanglurTriangle(pos, other, top))
    {
      throw std::logic_error("Incorrect description regular");
    }
    top_ = other;
    other_ = top;
  }
  sides_cnt_ = getCntSides();
  if (sides_cnt_ < 3)
  {
    throw std::logic_error("Incorrect description regular");
  }
  frame_rect_ = setFrameRect();
}
double alymova::Regular::getArea() const noexcept
{
  double radius_small = getVector(pos_, other_);
  double other_side = getVector(top_, other_);
  return 0.5 * radius_small * other_side * sides_cnt_ * 2.0;
}
alymova::rectangle_t alymova::Regular::getFrameRect() const noexcept
{
  return frame_rect_;
}
void alymova::Regular::move(double shift_x, double shift_y) noexcept
{
  point_t shift_point{shift_x, shift_y};
  pos_ += shift_point;
  top_ += shift_point;
  other_ += shift_point;
  alymova::moveFrameRect(frame_rect_, shift_x, shift_y);
}
void alymova::Regular::move(point_t point) noexcept
{
  double shift_x = point.x - pos_.x;
  double shift_y = point.y - pos_.y;
  move(shift_x, shift_y);
}
void alymova::Regular::unsafeScale(double ratio) noexcept
{
  top_.x = pos_.x + (top_.x - pos_.x) * ratio;
  top_.y = pos_.y + (top_.y - pos_.y) * ratio;
  other_.x = pos_.x + (other_.x - pos_.x) * ratio;
  other_.y = pos_.y + (other_.y - pos_.y) * ratio;
  alymova::scaleFrameRect(frame_rect_, ratio);
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
size_t alymova::Regular::getCntSides() const noexcept
{
  double radius_big = getVector(pos_, top_);
  double radius_small = getVector(pos_, other_);
  double sides = PI / (std::acos(radius_small / radius_big));
  size_t round_sides = std::round(sides);
  if (std::abs((std::cos(180 / std::round(sides) * PI / 180)) - (radius_small / radius_big)) < inaccuracy)
  {
    return round_sides;
  }
  return 0;
}
alymova::rectangle_t alymova::Regular::setFrameRect() noexcept
{
  double radius_big = getVector(pos_, top_);
  double other_side = getVector(top_, other_);
  double low_left_x = std::numeric_limits< double >::max();
  double low_left_y = std::numeric_limits< double >::max();
  double upp_right_x = std::numeric_limits< double >::min();
  double upp_right_y = std::numeric_limits< double >::min();
  double angle_start = std::acos(other_side / radius_big);
  if (top_.y == pos_.y)
  {
    angle_start = 0;
  }
  for (size_t i = 0; i < sides_cnt_; i++)
  {
    double angle_now = angle_start + i * 2 * PI / sides_cnt_;
    low_left_x = std::min(low_left_x, pos_.x + radius_big * std::cos(angle_now));
    low_left_y = std::min(low_left_y, pos_.y + radius_big * std::sin(angle_now));
    upp_right_x = std::max(upp_right_x, pos_.x + radius_big * std::cos(angle_now));
    upp_right_y = std::max(upp_right_y, pos_.y + radius_big * std::sin(angle_now));
  }
  double width = upp_right_x - low_left_x;
  double height = upp_right_y - low_left_y;
  point_t pos = {(low_left_x + width / 2.0), (upp_right_y - height / 2.0)};
  return rectangle_t{width, height, pos};
}
