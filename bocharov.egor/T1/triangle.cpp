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
    throw std::invalid_argument("error arguments for triangle");
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
  a_ = movePoint(a_, x, y);
  b_ = movePoint(b_, x, y);
  c_ = movePoint(c_, x, y);
}

void bocharov::Triangle::scale(double ratio)
{
  point_t pos = getFrameRect().pos;
  a_ = scalePoint(a_, pos, ratio);
  b_ = scalePoint(b_, pos, ratio);
  c_ = scalePoint(c_, pos, ratio);
}
