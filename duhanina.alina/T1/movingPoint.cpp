#include "movingPoint.hpp"

duhanina::point_t duhanina::calculateOffset(const duhanina::point_t& currentPos, const duhanina::point_t& newPos)
{
  return { newPos.x - currentPos.x, newPos.y - currentPos.y };
}

void duhanina::movePoint(duhanina::point_t& pos, double dx, double dy)
{
  pos.x += dx;
  pos.y += dy;
}

duhanina::point_t duhanina::scalePoint(const duhanina::point_t& point, const duhanina::point_t& origin, double k)
{
  return { origin.x + (point.x - origin.x) * k, origin.y + (point.y - origin.y) * k };
}
