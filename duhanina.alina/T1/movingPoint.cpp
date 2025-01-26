#include "movingPoint.hpp"

duhanina::point_t duhanina::calculateOffset(const point_t& currentPos, const point_t& newPos)
{
  return { newPos.x - currentPos.x, newPos.y - currentPos.y };
}

duhanina::point_t duhanina::movePoint(point_t& pos, double dx, double dy)
{
  return { pos.x + dx, pos.y + dy };
}

duhanina::point_t duhanina::scalePoint(const point_t& point, const point_t& origin, double k)
{
  return { origin.x + (point.x - origin.x) * k, origin.y + (point.y - origin.y) * k };
}
