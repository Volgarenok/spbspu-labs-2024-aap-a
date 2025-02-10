#include "triangle.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>

bocharov::Triangle::Triangle(point_t a, point_t b, point_t c):
 a_(a),
 b_(b),
 c_(c)
{
  if ((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) == 0)
  {
    throw std::invalid_argument("error arguments for triangle\n");
  }
}
double bocharov::Triangle::getArea() const
{
  return std::abs(((b_.x - a_.x) * (c_.y - a_.y) - (c_.x - a_.x) * (b_.y - a_.y))) / 2.0;
}

bocharov::rectangle_t bocharov::Triangle::getFrameRect() const
{
  double maxX = std::max(a_.x, std::max(b_.x, c_.x));
  double maxY = std::max(a_.y, std::max(b_.y, c_.y));
  double minX = std::min(a_.x, std::min(b_.x, c_.x));
  double minY = std::min(a_.y, std::min(b_.y, c_.y));
  double height = maxY - minY;
  double width = maxX - minX;
  point_t pos = {minX + (width / 2.0), minY + (height / 2.0)};
  return {width, height, pos};
}

void bocharov::Triangle::move(point_t centerP)
{
  point_t pos = getFrameRect().pos;
  double moveX = centerP.x - pos.x;
  double moveY = centerP.y - pos.y;
  move(moveX, moveY);
}

void bocharov::Triangle::move(double x, double y)
{
  a_.x += x;
  a_.y += y;
  b_.x += x;
  b_.y += y;
  c_.x += x;
  c_.y += y;
}

void bocharov::Triangle::scale(double ratio)
{
  point_t pos = getFrameRect().pos;
  a_.x = (a_.x - pos.x) * ratio + pos.x;
  a_.y = (a_.y - pos.y) * ratio + pos.y;
  b_.x = (b_.x - pos.x) * ratio + pos.x;
  b_.y = (b_.y - pos.y) * ratio + pos.y;
  c_.x = (c_.x - pos.x) * ratio + pos.x;
  c_.y = (c_.y - pos.y) * ratio + pos.y;
}
