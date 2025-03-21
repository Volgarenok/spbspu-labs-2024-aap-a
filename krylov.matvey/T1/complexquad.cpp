#include "complexquad.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "triangle.hpp"

krylov::Complexquad::Complexquad(const point_t& a, const point_t& b, const point_t& c, const point_t& d):
  t1_(a, krylov::findIntersection(a, b, c, d), {(a.x + d.x) / 2, (a.y + d.y) / 2}),
  t2_(d, krylov::findIntersection(a, b, c, d), {(a.x + d.x) / 2, (a.y + d.y) / 2}),
  t3_(c, krylov::findIntersection(a, b, c, d), {(b.x + c.x) / 2, (b.y + c.y) / 2}),
  t4_(b, krylov::findIntersection(a, b, c, d), {(b.x + c.x) / 2, (b.y + c.y) / 2})
{
  const point_t p = krylov::findIntersection(a, b, c, d);
  bool condition = (a.x == b.x && a.y == b.y) || (b.x == c.x && b.y == c.y);
  condition = condition || (c.x == d.x && c.y == d.y) || (a.x == c.x && a.y == c.y);
  condition = condition || (a.x == d.x && a.y == d.y) || (b.x == d.x && b.y == d.y);

  bool isNotOnSegments = !(krylov::isPointOnSegment(p, a, b) && krylov::isPointOnSegment(p, c, d));
  condition = condition || isNotOnSegments;

  bool isNotSamePoint = (p.x == a.x && p.y == a.y) || (p.x == b.x && p.y == b.y);
  isNotSamePoint = isNotSamePoint || (p.x == c.x && p.y == c.y) || (p.x == d.x && p.y == d.y);
  condition = condition || isNotSamePoint;
  bool isComplexquad = condition;
  if (isComplexquad)
  {
    throw std::invalid_argument("Invalid complexquad coordinates");
  }
  t1Center_ = t1_.getFrameRect().pos;
  t2Center_ = t2_.getFrameRect().pos;
  t3Center_ = t3_.getFrameRect().pos;
  t4Center_ = t4_.getFrameRect().pos;
  complexquadFrameCenter_ = getFrameRect().pos;
}
double krylov::Complexquad::getArea() const
{
  return t1_.getArea() + t2_.getArea() + t3_.getArea() + t4_.getArea();
}
krylov::rectangle_t krylov::Complexquad::getFrameRect() const
{
  rectangle_t f1 = t1_.getFrameRect();
  rectangle_t f2 = t2_.getFrameRect();
  rectangle_t f3 = t3_.getFrameRect();
  rectangle_t f4 = t4_.getFrameRect();
  double minX = std::min({f1.pos.x - f1.width / 2, f2.pos.x - f2.width / 2, f3.pos.x - f3.width / 2, f4.pos.x - f4.width / 2});
  double maxX = std::max({f1.pos.x + f1.width / 2, f2.pos.x + f2.width / 2, f3.pos.x + f3.width / 2, f4.pos.x + f4.width / 2});
  double maxY = std::max({f1.pos.y + f1.height / 2, f2.pos.y + f2.height / 2, f3.pos.y + f3.height / 2, f4.pos.y + f4.height / 2});
  double minY = std::min({f1.pos.y - f1.height / 2, f2.pos.y - f2.height / 2, f3.pos.y - f3.height / 2, f4.pos.y - f4.height / 2});
  point_t center = {minX + (maxX - minX) / 2, minY + (maxY - minY) / 2};
  return rectangle_t{maxX - minX, maxY - minY, center};
}
void krylov::Complexquad::move(const point_t& point)
{
  t1_.move(point);
  t2_.move(point);
  t3_.move(point);
  t4_.move(point);
}
void krylov::Complexquad::move(double dx, double dy)
{
  t1_.move(dx, dy);
  t2_.move(dx, dy);
  t3_.move(dx, dy);
  t4_.move(dx, dy);
}
void krylov::Complexquad::unsafeScale(double factor) noexcept
{
  point_t center = getFrameRect().pos;
  t1_.scale(factor);
  t2_.scale(factor);
  t3_.scale(factor);
  t4_.scale(factor);
  double dx = (complexquadFrameCenter_.x - center.x) * factor;
  double dy = (complexquadFrameCenter_.y - center.y) * factor;
  t1_.move((t1Center_.x - center.x) * factor - dx, (t1Center_.y - center.y) * factor - dy);
  t2_.move((t2Center_.x - center.x) * factor - dx, (t2Center_.y - center.y) * factor - dy);
  t3_.move((t3Center_.x - center.x) * factor - dx, (t3Center_.y - center.y) * factor - dy);
  t4_.move((t4Center_.x - center.x) * factor - dx, (t4Center_.y - center.y) * factor - dy);
}

bool krylov::isPointOnSegment(const point_t& point, const point_t& segStart, const point_t& segEnd)
{
  bool isXCorrect = std::min(segStart.x, segEnd.x) <= point.x && point.x <= std::max(segStart.x, segEnd.x);
  bool isYCorrect = std::min(segStart.y, segEnd.y) <= point.y && point.y <= std::max(segStart.y, segEnd.y);
  return isXCorrect && isYCorrect;
}
krylov::point_t krylov::findIntersection(const point_t& a, const point_t& b, const point_t& c, const point_t& d)
{
  const double m1 = (b.y - a.y) / (b.x - a.x);
  const double m2 = (d.y - c.y) / (d.x - c.x);
  const double b1 = a.y - m1 * a.x;
  const double b2 = c.y - m2 * c.x;
  point_t intersectionPoint = {(b2 - b1) / (m1 - m2), m1 * ((b2 - b1) / (m1 - m2)) + b1};
  return intersectionPoint;
}
