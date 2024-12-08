#include "regular.hpp"
#include <cmath>
#include <stdexcept>

namespace tkach
{
  double getDist(point_t point1, point_t point2)
  {
    return std::sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
  }
  bool isEqualPoints(point_t point1, point_t point2)
  {
    if (point1.x == point2.x && point1.y == point2.y) 
    {
      return true;
    }
    return false;
  }
  void getMaxSide(double &first_side, double &second_side, double &third_side)
  {
    if (first_side < second_side)
    {
      std::swap(first_side, second_side);
    }
    if (first_side < third_side)
    {
      std::swap(first_side, third_side);
    }
  }
}
tkach::Regular::Regular(point_t first_point, point_t second_point, point_t third_point)
{
  double first_side = getDist(first_point, second_point);
  double second_side = getDist(second_point, third_point);
  double third_side = getDist(third_point, first_point);
  getMaxSide(first_side, second_side, third_side);
  if (first_side * first_side - (second_side * second_side + third_side * third_side) > 0.0001)
  {
    throw std::logic_error("Triangle is not right");
  }
  if (isEqualPoints(first_point,second_point) || isEqualPoints(first_point,third_point) || isEqualPoints(third_point,second_point))
  {
    throw std::logic_error("Triangle doesn`t exist");
  }
  first_point_ = first_point;
  second_point_ = second_point;
  third_point_ = third_point;
}
double tkach::Regular::getArea() const noexcept
{
  double first_side = getDist(first_point_, second_point_);
  double second_side = getDist(second_point_, third_point_);
  double third_side = getDist(third_point_, first_point_);
  getMaxSide(first_side, second_side, third_side);
  return (second_side * third_side * 2.0 * M_PI / asin(third_side * second_side * 2.0 / (first_side * first_side)));
}
tkach::rectangle_t tkach::Regular::getFrameRect() const noexcept
{
  double first_side = getDist(first_point_, second_point_);
  double second_side = getDist(second_point_, third_point_);
  double third_side = getDist(third_point_, first_point_);
  getMaxSide(first_side, second_side, third_side);
  rectangle_t frame_rect;
  frame_rect.height = 2 * first_side;
  frame_rect.width = 2 * first_side;
  frame_rect.pos.x = first_point_.x;
  frame_rect.pos.y = first_point_.y;
  return frame_rect;
}
void tkach::Regular::move(double add_to_x, double add_to_y) noexcept
{
  first_point_.x += add_to_x;
  first_point_.y += add_to_y;
}
void tkach::Regular::move(point_t point_to_move) noexcept
{
  first_point_ = point_to_move;
}
void tkach::Regular::scale(double multiplier) noexcept
{
  second_point_.x = first_point_.x + (second_point_.x - first_point_.x) * multiplier;
  second_point_.y = first_point_.y + (second_point_.y - first_point_.y) * multiplier;
  third_point_.x = first_point_.x + (third_point_.x - first_point_.x) * multiplier;
  third_point_.y = first_point_.y + (third_point_.y - first_point_.y) * multiplier;
}