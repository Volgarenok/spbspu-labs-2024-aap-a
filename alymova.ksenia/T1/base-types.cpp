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
  return (point1.x < point2.x && point1.y < point2.y);
}
alymova::point_t alymova::getShiftFrameRect(rectangle_t rect1, rectangle_t rect2) noexcept
{
  return {rect2.pos.x - rect1.pos.x, rect2.pos.y - rect1.pos.y};
}
alymova::point_t alymova::getLowLeftFrameRect(rectangle_t rect) noexcept
{
  return {rect.pos.x - rect.width / 2.0, rect.pos.y - rect.height / 2.0};
}
alymova::point_t alymova::getUppRightFrameRect(rectangle_t rect) noexcept
{
  return {rect.pos.x + rect.width / 2.0, rect.pos.y + rect.height / 2.0};
}
