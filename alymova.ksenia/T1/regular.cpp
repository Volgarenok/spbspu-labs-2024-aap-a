#include "regular.hpp"
#include <cmath>
#include <stdexcept>
constexpr double PI = std::acos(-1.0);
constexpr double inaccuracy = 0.0000000001;
alymova::Regular::Regular(const point_t& pos, const point_t& top, const point_t& other):
  pos_(pos),
  top_(top),
  other_(other)
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
  if (getCntSides() < 3)
  {
    throw std::logic_error("Incorrect description regular");
  }
}
alymova::Regular::Regular(const Regular& other):
  pos_(other.pos_),
  top_(other.top_),
  other_(other.other_)
{}
double alymova::Regular::getArea() const noexcept
{
  double radius_small = getVector(pos_, other_);
  double other_side = getVector(top_, other_);
  return 0.5 * radius_small * other_side * getCntSides() * 2.0;
}
alymova::rectangle_t alymova::Regular::getFrameRect() const noexcept
{
  size_t sides_cnt = getCntSides();
  double radius_big = getVector(pos_, top_);
  double other_side = getVector(top_, other_);
  double angle_start = std::acos(other_side / radius_big);
  rectangle_t max_frame_rect = getMaxFrameRect();
  if (top_.y == pos_.y)
  {
    angle_start = 0;
  }
  for (size_t i = 0; i < sides_cnt; i++)
  {
    double angle_now = angle_start + i * 2 * PI / sides_cnt;
    changeFrameRect(max_frame_rect, pos_.x + radius_big * std::cos(angle_now), pos_.y + radius_big * std::sin(angle_now),
      pos_.x + radius_big * std::cos(angle_now), pos_.y + radius_big * std::sin(angle_now));
  }
  return max_frame_rect;
}
void alymova::Regular::move(double shift_x, double shift_y) noexcept
{
  point_t shift_point{shift_x, shift_y};
  pos_ += shift_point;
  top_ += shift_point;
  other_ += shift_point;
}
void alymova::Regular::move(const point_t& point) noexcept
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
}
alymova::Shape* alymova::Regular::clone() const
{
  return new Regular(*this);
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
