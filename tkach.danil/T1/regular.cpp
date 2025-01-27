#include "regular.hpp"
#include <cmath>
#include <stdexcept>

namespace
{
  bool compareDoubles(const double first, const double second)
  {
    return std::fabs(first - second) > 0.0001;
  }

  double getDist(const tkach::point_t& point1, const tkach::point_t& point2)
  {
    return std::sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
  }

  bool isEqualPoints(const tkach::point_t& point1, const tkach::point_t& point2)
  {
    return point1.x == point2.x && point1.y == point2.y;
  }

  tkach::point_t getSecondPoint(const tkach::point_t& first, const tkach::point_t& second, const tkach::point_t& third)
  {
    return getDist(first, third) > getDist(first, second) ? third : second;
  }

  tkach::point_t getThirdPoint(const tkach::point_t& first, const tkach::point_t& second, const tkach::point_t& third)
  {
    return getDist(first, third) > getDist(first, second) ? second : third;
  }
}

size_t tkach::Regular::getSideAmount() const
{
  double dist_first_to_third = getDist(first_point_, third_point_);
  double dist_first_to_second = getDist(first_point_, second_point_);
  const double res = std::acos(-1.0) / (std::acos(dist_first_to_third / dist_first_to_second));
  size_t round_res = std::round(res);
  return compareDoubles(res, round_res) ? 0 : round_res;
}

tkach::Regular::Regular(const point_t& first_point, const point_t& second_point, const point_t& third_point):
  first_point_(first_point),
  second_point_(getSecondPoint(first_point, second_point, third_point)),
  third_point_(getThirdPoint(first_point, second_point, third_point))
{
  double first_side_squarred = std::pow(getDist(first_point_, second_point_), 2);
  double second_side_squarred = std::pow(getDist(third_point_, second_point_), 2);
  double third_side_squarred = std::pow(getDist(first_point_, third_point_), 2);
  if (compareDoubles(first_side_squarred, second_side_squarred + third_side_squarred))
  {
    throw std::logic_error("Triangle is not right");
  }
  bool equal_points[3];
  equal_points[0] = isEqualPoints(first_point, second_point);
  equal_points[1] = isEqualPoints(first_point, third_point);
  equal_points[2] = isEqualPoints(third_point, second_point);
  if (equal_points[0] || equal_points[1] || equal_points[2])
  {
    throw std::logic_error("Triangle doesn`t exist");
  }
  if (getSideAmount() < 3)
  {
    throw std::logic_error("Shape doesn`t exist");
  }
}

tkach::Shape* tkach::Regular::clone() const
{
  return new Regular(*this);
}

double tkach::Regular::getArea() const
{
  return (getSideAmount() * getDist(second_point_, third_point_) * getDist(first_point_, third_point_));
}

tkach::rectangle_t tkach::Regular::getFrameRect() const
{
  point_t start_point = second_point_;
  const double step_angle = 2.0 * std::acos(-1.0) / getSideAmount();
  double top = start_point.y;
  double bot = start_point.y;
  double left = start_point.x;
  double right = start_point.x;
  point_t new_point = {start_point.x + 1, start_point.y + 1};
  point_t start_point_temp = start_point;
  double new_angle = std::acos((start_point.x - first_point_.x) / getDist(first_point_, second_point_));
  while ((compareDoubles(new_point.x, start_point.x)) || (compareDoubles(new_point.y, start_point.y)))
  {
    new_angle += step_angle;
    start_point_temp.x = first_point_.x + getDist(first_point_, second_point_) * std::cos(new_angle);
    start_point_temp.y = first_point_.y + getDist(first_point_, second_point_) * std::sin(new_angle);
    new_point = start_point_temp;
    bot = std::min(bot, start_point_temp.y);
    top = std::max(top, start_point_temp.y);
    left = std::min(left, start_point_temp.x);
    right = std::max(right, start_point_temp.x);
  }
  return {right - left, top - bot, {(right + left) / 2.0, (top + bot) / 2.0}};
}

void tkach::Regular::move(const double add_to_x, const double add_to_y)
{
  addToPoint(first_point_, add_to_x, add_to_y);
  addToPoint(second_point_, add_to_x, add_to_y);
  addToPoint(third_point_, add_to_x, add_to_y);
}

void tkach::Regular::move(const point_t& point_to_move)
{
  addToPoint(second_point_, point_to_move.x - first_point_.x, point_to_move.y - first_point_.y);
  addToPoint(third_point_, point_to_move.x - first_point_.x, point_to_move.y - first_point_.y);
  first_point_ = point_to_move;
}

void tkach::Regular::doUnsafeScale(const double multiplier)
{
  second_point_ = getShiftedPointFromAnother(second_point_, first_point_, multiplier);
  third_point_ = getShiftedPointFromAnother(third_point_, first_point_, multiplier);
}
