#include "complexquad.hpp"
#include "triangle.hpp"
#include <algorithm>
#include <stdexcept>

krylov::Complexquad::Complexquad(const point_t& a, const point_t& b, const point_t& c, const point_t& d):
  a_(a),
  b_(b),
  c_(c),
  d_(d)
{
  bool invalid = (a_.x == b_.x && a_.y == b_.y) || (b_.x == c_.x && b_.y == c_.y) || (c_.x == d_.x && c_.y == d_.y)
    || (a_.x == c_.x && a_.y == c_.y) || (a_.x == d_.x && a_.y == d_.y) || (b_.x == d_.x && b_.y == d_.y);

  if (invalid)
  {
    throw std::invalid_argument("Invalid complexquad coordinates");
  }
}

bool krylov::Complexquad::isPointOnSegment(const point_t& point, const point_t& segStart, const point_t& segEnd) const
{
  return std::min(segStart.x, segEnd.x) <= point.x && point.x <= std::max(segStart.x, segEnd.x)
    && std::min(segStart.y, segEnd.y) <= point.y && point.y <= std::max(segStart.y, segEnd.y);
}

krylov::point_t krylov::Complexquad::findIntersection(const point_t& a, const point_t& b, const point_t& c, const point_t& d) const
{
  double m1 = (b.y - a.y) / (b.x - a.x);
  double m2 = (d.y - c.y) / (d.x - c.x);
  double b1 = a.y - m1 * a.x;
  double b2 = c.y - m2 * c.x;
  point_t intersectionPoint = {(b2 - b1) / (m1 - m2), m1 * ((b2 - b1) / (m1 - m2)) + b1};

  if (isPointOnSegment(intersectionPoint, a, b) && isPointOnSegment(intersectionPoint, c, d))
  {
    return intersectionPoint;
  }
  return {0, 0};
}

double krylov::Complexquad::getArea() const
{
  point_t m1 = {(a_.x + c_.x) / 2, (a_.y + c_.y) / 2};
  point_t m2 = {(b_.x + d_.x) / 2, (b_.y + d_.y) / 2};

  krylov::Triangle t1(a_, m1, m2);
  krylov::Triangle t2(m1, c_, m2);
  krylov::Triangle t3(b_, m1, m2);
  krylov::Triangle t4(m1, d_, m2);

  return t1.getArea() + t2.getArea() + t3.getArea() + t4.getArea();
}

krylov::rectangle_t krylov::Complexquad::getFrameRect() const
{
  double minX = std::min({a_.x, b_.x, c_.x, d_.x});
  double maxX = std::max({a_.x, b_.x, c_.x, d_.x});
  double maxY = std::max({a_.y, b_.y, c_.y, d_.y});
  double minY = std::min({a_.y, b_.y, c_.y, d_.y});
  point_t center = {minX + (maxX - minX) / 2, minY + (maxY - minY) / 2};
  return rectangle_t{maxX - minX, maxY - minY, center};
}

void krylov::Complexquad::move(const point_t& point)
{
  point_t center = getFrameRect().pos;
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}

void krylov::Complexquad::move(double dx, double dy)
{
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
  d_.x += dx;
  d_.y += dy;
}

void krylov::Complexquad::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }
  point_t center = getFrameRect().pos;
  a_.x = center.x + factor * (a_.x - center.x);
  a_.y = center.y + factor * (a_.y - center.y);
  b_.x = center.x + factor * (b_.x - center.x);
  b_.y = center.y + factor * (b_.y - center.y);
  c_.x = center.x + factor * (c_.x - center.x);
  c_.y = center.y + factor * (c_.y - center.y);
  d_.x = center.x + factor * (d_.x - center.x);
  d_.y = center.y + factor * (d_.y - center.y);
}
