#include "rectangle.hpp"
#include <stdexcept>

tkach::Rectangle::Rectangle(point_t left_bot_point, point_t right_top_point)
{
  if (left_bot_point.x >= right_top_point.x || left_bot_point.y >= right_top_point.y)
  {
    throw std::logic_error("Invalid left/right points");
  }
  left_bot_point_ = left_bot_point;
  right_top_point_ = right_top_point;
}

double tkach::Rectangle::getArea() const noexcept
{
  return (right_top_point_.y - left_bot_point_.y) * (right_top_point_.x - left_bot_point_.x);
}

tkach::rectangle_t tkach::Rectangle::getFrameRect() const noexcept
{
  rectangle_t frame_rect;
  frame_rect.height = right_top_point_.y - left_bot_point_.y;
  frame_rect.width = right_top_point_.x - left_bot_point_.x;
  frame_rect.pos.x = left_bot_point_.x + (right_top_point_.x - left_bot_point_.x) / 2.0;
  frame_rect.pos.y = left_bot_point_.y + (right_top_point_.y - left_bot_point_.y) / 2.0;
  return frame_rect;
}
void tkach::Rectangle::move(double add_to_x, double add_to_y) noexcept
{
  left_bot_point_.x += add_to_x;
  left_bot_point_.y += add_to_y;
  right_top_point_.x += add_to_x;
  right_top_point_.y += add_to_y;
}
void tkach::Rectangle::move(point_t point_to_move) noexcept
{
  point_t center_frame = getFrameRect().pos;
  move(point_to_move.x - center_frame.x, point_to_move.y - center_frame.y);
}
void tkach::Rectangle::scale(double multiplier) noexcept
{
  point_t center_frame = getFrameRect().pos;
  left_bot_point_.x = center_frame.x - (center_frame.x - left_bot_point_.x) * multiplier;
  left_bot_point_.y = center_frame.y - (center_frame.y - left_bot_point_.y) * multiplier;
  right_top_point_.x = center_frame.x + (center_frame.x - right_top_point_.x) * multiplier;
  right_top_point_.y = center_frame.y + (center_frame.y - right_top_point_.y) * multiplier;
}