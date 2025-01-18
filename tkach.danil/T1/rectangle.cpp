#include "rectangle.hpp"
#include <stdexcept>

tkach::Rectangle::Rectangle(const point_t& left_bot_point, const point_t& right_top_point):
  left_bot_point_(left_bot_point),
  right_top_point_(right_top_point)
{
  if (left_bot_point.x >= right_top_point.x || left_bot_point.y >= right_top_point.y)
  {
    throw std::logic_error("Invalid left/right points");
  }
}

double tkach::Rectangle::getArea() const
{
  return (right_top_point_.y - left_bot_point_.y) * (right_top_point_.x - left_bot_point_.x);
}

tkach::Shape* tkach::Rectangle::clone() const
{
  return new Rectangle(*this);
}

tkach::rectangle_t tkach::Rectangle::getFrameRect() const
{
  double height = right_top_point_.y - left_bot_point_.y;
  double width = right_top_point_.x - left_bot_point_.x;
  return {width, height, getShiftedPointFromAnother(right_top_point_, left_bot_point_, 0.5)};
}

void tkach::Rectangle::move(const double add_to_x, const double add_to_y)
{
  addToPoint(left_bot_point_, add_to_x, add_to_y);
  addToPoint(right_top_point_, add_to_x, add_to_y);
}

void tkach::Rectangle::move(const point_t& point_to_move)
{
  point_t center_frame = getFrameRect().pos;
  move(point_to_move.x - center_frame.x, point_to_move.y - center_frame.y);
}

void tkach::Rectangle::doUnsafeScale(const double multiplier)
{
  point_t center_frame = getFrameRect().pos;
  left_bot_point_ = getShiftedPointFromAnother(left_bot_point_, center_frame, multiplier);
  right_top_point_ = getShiftedPointFromAnother(right_top_point_, center_frame, multiplier);
}
