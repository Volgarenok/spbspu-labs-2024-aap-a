#include "base-types.hpp"
#include <stdexcept>
alymova::point_t alymova::operator+=(point_t& point, point_t shift_point)
{
  point.x += shift_point.x;
  point.y += shift_point.y;
  return point;
}
alymova::point_t alymova::operator*=(point_t& point, double ratio)
{
  point.x *= ratio;
  point.y *= ratio;
  return point;
}
bool alymova::operator<(point_t point1, point_t point2)
{
  if (point1.x < point2.x && point1.y < point2.y)
  {
    return true;
  }
  return false;
}

double alymova::getAreaFrameRect(rectangle_t rect) noexcept
{
  return rect.width * rect.height;
}
void alymova::moveFrameRect(rectangle_t& rect, double shift_x, double shift_y) noexcept
{
  point_t shift_point_ = {shift_x, shift_y};
  rect.pos += shift_point_;
}
void alymova::scaleFrameRect(rectangle_t& rect, double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("The scale ratio should be positive");
  }
  if (ratio == 1)
  {
    return;
  }
  rect.width *= ratio;
  rect.height *= ratio;
}
alymova::point_t alymova::getShiftFrameRect(rectangle_t rect1, rectangle_t rect2) noexcept
{
  point_t shift_point = {rect2.pos.x - rect1.pos.x, rect2.pos.y - rect1.pos.y};
  return shift_point;
}
alymova::point_t alymova::getLowLeftFrameRect(rectangle_t rect) noexcept
{
  point_t low_left{rect.pos.x - rect.width / 2.0, rect.pos.y - rect.height / 2.0};
  return low_left;
}
alymova::point_t alymova::getUppRightFrameRect(rectangle_t rect) noexcept
{
  point_t upp_right{rect.pos.x + rect.width / 2.0, rect.pos.y + rect.height / 2.0};
  return upp_right;
}
