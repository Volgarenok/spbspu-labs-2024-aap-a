#include "concave.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"

namespace bocharov
{
  bool isTriangle(point_t a, point_t b, point_t c);
  bool isPointInTriangle(point_t a, point_t b, point_t c, point_t d);
  double getMyArea(point_t a, point_t b, point_t c);
  bool isDupePoint(point_t p1, point_t p2, point_t p3, point_t p4);
}

bool bocharov::isDupePoint(point_t p1, point_t p2, point_t p3, point_t p4)
{
  if ((p1.x == p2.x && p1.y == p2.y) || (p1.x == p3.x && p1.y == p3.y) || (p1.x == p4.x && p1.y == p4.y) || (p2.x == p3.x && p2.y == p3.y)
     || (p2.x == p4.x && p2.y == p4.y) || (p3.x == p4.x && p3.y == p4.y))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool bocharov::isTriangle(point_t a, point_t b, point_t c)
{
  return !(((a.x == b.x) && (a.x == c.x)) || ((a.y == b.y) && (a.y == c.y)));
}

double bocharov::getMyArea(point_t a, point_t b, point_t c)
{
  return std::abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y -b.y)) / 2.0);
}

bool bocharov::isPointInTriangle(point_t a, point_t b, point_t c, point_t d)
{
  const double epsilon = 1e-9;
  double s = getMyArea(a, b, c);
  double s1 = getMyArea(a, b, d);
  double s2 = getMyArea(a, d, c);
  double s3 = getMyArea(d, b, c);
  return std::abs(s - (s1 + s2 + s3)) < epsilon;
}

bocharov::Concave::Concave(point_t a, point_t b, point_t c, point_t d):
 a_({0.0, 0.0}),
 b_({0.0, 0.0}),
 c_({0.0, 0.0}),
 d_({0.0, 0.0})
{
  if (!isTriangle(d, b, c) || !isPointInTriangle(a, b, c, d) || isDupePoint(a, b, c, d))
  {
    throw std::invalid_argument("Error witch point for concave\n");
  }
  a_ = b;
  b_ = d;
  c_ = c;
  d_ = a;
}

double bocharov::Concave::getArea() const
{
  return std::abs(a_.x * b_.y + b_.x * c_.y + c_.x * d_.y + d_.x * a_.y - b_.x * a_.y - c_.x * b_.y - d_.x * c_.y - a_.x * d_.y) / 2.0;
}
bocharov::rectangle_t bocharov::Concave::getFrameRect() const
{
  double maxX = std::max(a_.x, std::max(b_.x, std::max(c_.x, d_.x)));
  double maxY = std::max(a_.y, std::max(b_.y, std::max(c_.y, d_.y)));
  double minY = std::min(a_.y, std::min(b_.y, std::min(c_.y, d_.y)));
  double minX = std::min(a_.x, std::min(b_.x, std::min(c_.x, d_.x)));
  rectangle_t result;
  result.height = maxY - minY;
  result.width = maxX - minX;
  result.pos.x = minX + (result.width / 2.0);
  result.pos.y = minY + (result.height / 2.0);
  return result;
}
void bocharov::Concave::move(double x, double y)
{
  a_.x += x;
  b_.x += x;
  c_.x += x;
  d_.x += x;
  a_.y += y;
  b_.y += y;
  c_.y += y;
  d_.y += y;
}

void bocharov::Concave::move(point_t point)
{
  double moveX = point.x - d_.x;
  double moveY = point.y - d_.y;
  move(moveX, moveY);
}

void bocharov::Concave::scale(double ratio)
{
  a_.x = (a_.x - d_.x) * ratio;
  b_.x = (b_.x - d_.x) * ratio;
  c_.x = (c_.x - d_.x) * ratio;
  a_.y = (a_.y - d_.y) * ratio;
  b_.y = (b_.y - d_.y) * ratio;
  c_.y = (c_.y - d_.y) * ratio;
}
