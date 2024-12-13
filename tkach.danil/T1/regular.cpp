#include "regular.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>

double tkach::Regular::getDist(point_t point1, point_t point2) const
{
  return std::sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
}
bool tkach::Regular::isEqualPoints(const point_t point1, const point_t point2) const
{
  if (point1.x == point2.x && point1.y == point2.y)
  {
    return true;
  }
  return false;
}
size_t tkach::Regular::getSideAmount() const
{
  const double res = std::acos(-1.0) / (std::acos(second_side_in_r_ / first_side_out_r_));
  if (std::fabs(res - std::round(res)) > 0.0001)
  {
    return 0;
  }
  return std::round(std::acos(-1.0) / (std::acos(second_side_in_r_ / first_side_out_r_)));
}

tkach::Regular::Regular(point_t first_point, point_t second_point, point_t third_point):
  first_point_(first_point),
  second_point_(second_point),
  third_point_(third_point),
  first_side_out_r_(getDist(first_point, second_point)),
  second_side_in_r_(getDist(first_point, third_point)),
  third_side_(getDist(second_point, third_point)),
  amount_of_sides_(0)
{
  if (second_side_in_r_ > first_side_out_r_)
  {
    std::swap(second_side_in_r_, first_side_out_r_);
  }
  if (std::fabs(first_side_out_r_ * first_side_out_r_ - (second_side_in_r_ * second_side_in_r_ + third_side_ * third_side_)) > 0.00001)
  {
    throw std::logic_error("Triangle is not right");
  }
  if (isEqualPoints(first_point,second_point) || isEqualPoints(first_point,third_point) || isEqualPoints(third_point,second_point))
  {
    throw std::logic_error("Triangle doesn`t exist");
  }
  amount_of_sides_ = getSideAmount();
  if (amount_of_sides_ == 0)
  {
    throw std::logic_error("Shape doesn`t exist");
  }
}
double tkach::Regular::getArea() const
{
  return (amount_of_sides_ * third_side_ * second_side_in_r_);
}
tkach::rectangle_t tkach::Regular::getFrameRect() const
{
  rectangle_t frame_rect;
  frame_rect.height = 0;
  frame_rect.width = 0;
  frame_rect.pos.x = first_point_.x;
  frame_rect.pos.y = first_point_.y;
  point_t start_point, new_point, start_point_temp;
  const double step_angle = 2.0 * M_PI / amount_of_sides_;
  if (getDist(first_point_, second_point_) >= getDist(first_point_, third_point_))
  {
    start_point = second_point_;
  }
  else
  {
    start_point = third_point_;
  }
  new_point.x = start_point.x + 1;
  new_point.y = start_point.y + 1;
  start_point_temp = start_point;
  double new_angle = std::acos((start_point.x - first_point_.x) / first_side_out_r_);
  while((new_point.x - start_point.x > 0.0001) || (new_point.y - start_point.y > 0.0001))
  {
    new_angle += step_angle;
    start_point_temp.x = first_point_.x + first_side_out_r_ * std::cos(new_angle);
    start_point_temp.y = first_point_.y + first_side_out_r_ * std::sin(new_angle);
    new_point = start_point_temp;
    if (std::fabs(first_point_.x - start_point_temp.x) > frame_rect.width)
    {
      frame_rect.width = std::fabs(first_point_.x - start_point_temp.x);
    }
    if (std::fabs(first_point_.y - start_point_temp.y) > frame_rect.height)
    {
      frame_rect.height = std::fabs(first_point_.y - start_point_temp.y);
    }
  }
  frame_rect.width *= 2;
  frame_rect.height *= 2;
  return frame_rect;
}
void tkach::Regular::move(double add_to_x, double add_to_y)
{
  first_point_.x += add_to_x;
  first_point_.y += add_to_y;
  second_point_.x += add_to_x;
  second_point_.y += add_to_y;
  third_point_.x += add_to_x;
  third_point_.y += add_to_y;
}
void tkach::Regular::move(point_t point_to_move)
{
  second_point_.x += point_to_move.x - first_point_.x;
  second_point_.y += point_to_move.y - first_point_.y;
  third_point_.x += point_to_move.x - first_point_.x;
  third_point_.y += point_to_move.y - first_point_.y;
  first_point_ = point_to_move;
}
void tkach::Regular::scale(double multiplier)
{
  second_point_.x = first_point_.x + (second_point_.x - first_point_.x) * multiplier;
  second_point_.y = first_point_.y + (second_point_.y - first_point_.y) * multiplier;
  third_point_.x = first_point_.x + (third_point_.x - first_point_.x) * multiplier;
  third_point_.y = first_point_.y + (third_point_.y - first_point_.y) * multiplier;
  first_side_out_r_ *= multiplier;
  second_side_in_r_ *= multiplier;
  third_side_ *= multiplier;
}
