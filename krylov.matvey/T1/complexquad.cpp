#include "complexquad.hpp"
#include <algorithm>
#include <stdexcept>
#include "triangle.hpp"

namespace
{
  bool isPointOnSegment(const krylov::point_t& point, const krylov::point_t& segStart, const krylov::point_t& segEnd)
  {
    bool isXCorrect = std::min(segStart.x, segEnd.x) <= point.x && point.x <= std::max(segStart.x, segEnd.x);
    bool isYCorrect = std::min(segStart.y, segEnd.y) <= point.y && point.y <= std::max(segStart.y, segEnd.y);
    return isXCorrect && isYCorrect;
  }

  krylov::point_t findIntersection(const krylov::point_t& a, const krylov::point_t& b, const krylov::point_t& c, const krylov::point_t& d)
  {
    const double m1 = (b.y - a.y) / (b.x - a.x);
    const double m2 = (d.y - c.y) / (d.x - c.x);
    const double b1 = a.y - m1 * a.x;
    const double b2 = c.y - m2 * c.x;
    krylov::point_t intersectionPoint = {(b2 - b1) / (m1 - m2), m1 * ((b2 - b1) / (m1 - m2)) + b1};
    return intersectionPoint;
  }
}

krylov::Complexquad::Complexquad(const point_t& a, const point_t& b, const point_t& c, const point_t& d):
  t1_(a, findIntersection(a, b, c, d), {(a.x + d.x) / 2, (a.y + d.y) / 2}),
  t2_(d, findIntersection(a, b, c, d), {(a.x + d.x) / 2, (a.y + d.y) / 2}),
  t3_(c, findIntersection(a, b, c, d), {(b.x + c.x) / 2, (b.y + c.y) / 2}),
  t4_(b, findIntersection(a, b, c, d), {(b.x + c.x) / 2, (b.y + c.y) / 2}),
  intersectionPoint_(findIntersection(a, b, c, d))
{
  const point_t p = findIntersection(a, b, c, d);
  bool condition = (a.x == b.x && a.y == b.y) || (b.x == c.x && b.y == c.y);
  condition = condition || (c.x == d.x && c.y == d.y) || (a.x == c.x && a.y == c.y);
  condition = condition || (a.x == d.x && a.y == d.y) || (b.x == d.x && b.y == d.y);

  bool isNotOnSegments = !(isPointOnSegment(p, a, b) && isPointOnSegment(p, c, d));
  condition = condition || isNotOnSegments;

  bool isNotSamePoint = (p.x == a.x && p.y == a.y) || (p.x == b.x && p.y == b.y);
  isNotSamePoint = isNotSamePoint || (p.x == c.x && p.y == c.y) || (p.x == d.x && p.y == d.y);
  condition = condition || isNotSamePoint;
  bool isComplexquad = condition;
  if (isComplexquad)
  {
    throw std::invalid_argument("Invalid complexquad coordinates");
  }
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
  point_t center = getFrameRect().pos;
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  t1_.move(dx, dy);
  t2_.move(dx, dy);
  t3_.move(dx, dy);
  t4_.move(dx, dy);
  intersectionPoint_.x += dx;
  intersectionPoint_.y += dy;
}

void krylov::Complexquad::move(double dx, double dy)
{
  t1_.move(dx, dy);
  t2_.move(dx, dy);
  t3_.move(dx, dy);
  t4_.move(dx, dy);
  intersectionPoint_.x += dx;
  intersectionPoint_.y += dy;
}

void krylov::Complexquad::unsafeScale(double factor) noexcept
{
  t1_.scale(factor);
  t2_.scale(factor);
  t3_.scale(factor);
  t4_.scale(factor);
  point_t t1Cent = t1_.getFrameRect().pos;
  point_t t2Cent = t2_.getFrameRect().pos;
  point_t t3Cent = t3_.getFrameRect().pos;
  point_t t4Cent = t4_.getFrameRect().pos;
  point_t t1IP = {t1Cent.x + factor * (intersectionPoint_.x - t1Cent.x), t1Cent.y + factor * (intersectionPoint_.y - t1Cent.y)};
  point_t t2IP = {t2Cent.x + factor * (intersectionPoint_.x - t2Cent.x), t2Cent.y + factor * (intersectionPoint_.y - t2Cent.y)};
  point_t t3IP = {t3Cent.x + factor * (intersectionPoint_.x - t3Cent.x), t3Cent.y + factor * (intersectionPoint_.y - t3Cent.y)};
  point_t t4IP = {t4Cent.x + factor * (intersectionPoint_.x - t4Cent.x), t4Cent.y + factor * (intersectionPoint_.y - t4Cent.y)};
  t1_.move(intersectionPoint_.x - t1IP.x, intersectionPoint_.y - t1IP.y);
  t2_.move(intersectionPoint_.x - t2IP.x, intersectionPoint_.y - t2IP.y);
  t3_.move(intersectionPoint_.x - t3IP.x, intersectionPoint_.y - t3IP.y);
  t4_.move(intersectionPoint_.x - t4IP.x, intersectionPoint_.y - t4IP.y);
  point_t frame = getFrameRect().pos;
  double dx = (intersectionPoint_.x - frame.x) / factor;
  double dy = (intersectionPoint_.y - frame.y) / factor;
  t1_.move(dx, dy);
  t2_.move(dx, dy);
  t3_.move(dx, dy);
  t4_.move(dx, dy);
  intersectionPoint_.x += dx;
  intersectionPoint_.y += dy;
}
