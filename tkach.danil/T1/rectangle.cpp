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
  double frame_rect_pos_x = left_bot_point_.x + (right_top_point_.x - left_bot_point_.x) / 2.0;
  double frame_rect_pos_y = left_bot_point_.y + (right_top_point_.y - left_bot_point_.y) / 2.0;
  return {width, height, {frame_rect_pos_x, frame_rect_pos_y}};
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

void tkach::Rectangle::scaleUnsafe(const double multiplier)
{
  point_t center_frame = getFrameRect().pos;
  left_bot_point_.x = center_frame.x - (center_frame.x - left_bot_point_.x) * multiplier;
  left_bot_point_.y = center_frame.y - (center_frame.y - left_bot_point_.y) * multiplier;
  right_top_point_.x = center_frame.x + (right_top_point_.x - center_frame.x) * multiplier;
  right_top_point_.y = center_frame.y + (right_top_point_.y - center_frame.y) * multiplier;
}
