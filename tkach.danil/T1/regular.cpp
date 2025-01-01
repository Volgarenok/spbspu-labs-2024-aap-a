#include "regular.hpp"
#include <cmath>
#include <stdexcept>

double tkach::Regular::getDist(const point_t& point1, const point_t& point2) const
{
  return std::sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
}

bool tkach::Regular::isEqualPoints(const point_t& point1, const point_t& point2) const
{
  if (point1.x == point2.x && point1.y == point2.y)
  {
    return true;
  }
  return false;
}

size_t tkach::Regular::getSideAmount() const
{
  const double res = std::acos(-1.0) / (std::acos(getDist(first_point_, third_point_) / getDist(first_point_, second_point_)));
  if (std::fabs(res - std::round(res)) > 0.0001)
  {
    return 0;
  }
  return std::round(std::acos(-1.0) / (std::acos(getDist(first_point_, third_point_) / getDist(first_point_, second_point_))));
}

tkach::Regular::Regular(const point_t& first_point, const point_t& second_point, const point_t& third_point):
  first_point_(first_point),
  second_point_(second_point),
  third_point_(third_point)
{
  if (getDist(first_point, third_point) > getDist(first_point, second_point))
  {
    std::swap(second_point_, third_point_);
  }
  double first_side_squared = getDist(first_point_, second_point_) * getDist(first_point_, second_point_);
  double second_side_squared = getDist(third_point_, second_point_) * getDist(third_point_, second_point_);
  double third_side_squared = getDist(first_point_, third_point_) * getDist(first_point_, third_point_);
  if (std::fabs(first_side_squared - (second_side_squared + third_side_squared)) > 0.00001)
  {
    throw std::logic_error("Triangle is not right");
  }
  if (isEqualPoints(first_point,second_point) || isEqualPoints(first_point,third_point) || isEqualPoints(third_point,second_point))
  {
    throw std::logic_error("Triangle doesn`t exist");
  }
  if (getSideAmount() == 0)
  {
    throw std::logic_error("Shape doesn`t exist");
  }
}

double tkach::Regular::getArea() const
{
  return (getSideAmount() * getDist(second_point_, third_point_) * getDist(first_point_, third_point_));
}

tkach::rectangle_t tkach::Regular::getFrameRect() const
{
  double height = 0.0;
  double width = 0.0;
  point_t start_point, new_point, start_point_temp;
  const double step_angle = 2.0 * std::acos(-1.0) / getSideAmount();
  start_point = second_point_;
  new_point.x = start_point.x + 1;
  new_point.y = start_point.y + 1;
  start_point_temp = start_point;
  double new_angle = std::acos((start_point.x - first_point_.x) / getDist(first_point_, second_point_));
  while ((new_point.x - start_point.x > 0.0001) || (new_point.y - start_point.y > 0.0001))
  {
    new_angle += step_angle;
    start_point_temp.x = first_point_.x + getDist(first_point_, second_point_) * std::cos(new_angle);
    start_point_temp.y = first_point_.y + getDist(first_point_, second_point_) * std::sin(new_angle);
    new_point = start_point_temp;
    if (std::fabs(first_point_.x - start_point_temp.x) > width)
    {
      width = std::fabs(first_point_.x - start_point_temp.x);
    }
    if (std::fabs(first_point_.y - start_point_temp.y) > height)
    {
      height = std::fabs(first_point_.y - start_point_temp.y);
    }
  }
  width *= 2;
  height *= 2;
  return {width, height, {first_point_.x, first_point_.y}};
}

void tkach::Regular::move(const double add_to_x, const double add_to_y)
{
  addToPoint(first_point_, add_to_x, add_to_y);
  addToPoint(second_point_, add_to_x, add_to_y);
  addToPoint(third_point_, add_to_x, add_to_y);
}
void tkach::Regular::move(const point_t& point_to_move)
{
  second_point_.x += point_to_move.x - first_point_.x;
  second_point_.y += point_to_move.y - first_point_.y;
  third_point_.x += point_to_move.x - first_point_.x;
  third_point_.y += point_to_move.y - first_point_.y;
  first_point_ = point_to_move;
}
void tkach::Regular::scaleOneOfUniqueShapes(const double multiplier)
{
  second_point_.x = first_point_.x + (second_point_.x - first_point_.x) * multiplier;
  second_point_.y = first_point_.y + (second_point_.y - first_point_.y) * multiplier;
  third_point_.x = first_point_.x + (third_point_.x - first_point_.x) * multiplier;
  third_point_.y = first_point_.y + (third_point_.y - first_point_.y) * multiplier;
}
