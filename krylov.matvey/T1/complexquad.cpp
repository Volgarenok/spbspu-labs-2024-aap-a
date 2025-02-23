#include "complexquad.hpp"
#include <algorithm>
#include <stdexcept>
#include "triangle.hpp"

krylov::Complexquad::Complexquad(const point_t& a, const point_t& b, const point_t& c, const point_t& d):
  t1_(a, b, c),
  t2_(c, d, a),
  t3_(b, c, d),
  t4_(d, a, b)
{
  const point_t p = findIntersection(a, b, c, d);
  bool isComplexquad = (((a.x == b.x && a.y == b.y) || (b.x == c.x && b.y == c.y) || (c.x == d.x && c.y == d.y)
    || (a.x == c.x && a.y == c.y) || (a.x == d.x && a.y == d.y) || (b.x == d.x && b.y == d.y))
      && (!(isPointOnSegment(p, a, b) && isPointOnSegment(p, c, d))) && (!((p.x == a.x && p.y == a.y)
        || (p.x == b.x && p.y == b.y) || (p.x == c.x && p.y == c.y) || (p.x == d.x && p.y == d.y))));
  if (isComplexquad)
  {
    throw std::invalid_argument("Invalid complexquad coordinates");
  }
  const point_t m1 = {(a.x + d.x) / 2, (a.y + d.y) / 2};
  const point_t m2 = {(b.x + c.x) / 2, (b.y + c.y) / 2};
  t1_ = Triangle(a, p, m1);
  t2_ = Triangle(d, p, m1);
  t3_ = Triangle(c, p, m2);
  t4_ = Triangle(b, p, m2);
  t1Center_ = t1_.getFrameRect().pos;
  t2Center_ = t2_.getFrameRect().pos;
  t3Center_ = t3_.getFrameRect().pos;
  t4Center_ = t4_.getFrameRect().pos;
  complexquadFrameCenter_ = getFrameRect().pos;
}
bool krylov::Complexquad::isPointOnSegment(const point_t& point, const point_t& segStart, const point_t& segEnd) const
{
  return std::min(segStart.x, segEnd.x) <= point.x && point.x <= std::max(segStart.x, segEnd.x)
    && std::min(segStart.y, segEnd.y) <= point.y && point.y <= std::max(segStart.y, segEnd.y);
}
krylov::point_t krylov::Complexquad::findIntersection(const point_t& a, const point_t& b, const point_t& c, const point_t& d) const
{
  const double m1 = (b.y - a.y) / (b.x - a.x);
  const double m2 = (d.y - c.y) / (d.x - c.x);
  const double b1 = a.y - m1 * a.x;
  const double b2 = c.y - m2 * c.x;
  const point_t intersectionPoint = {(b2 - b1) / (m1 - m2), m1 * ((b2 - b1) / (m1 - m2)) + b1};
  return intersectionPoint;
}
double krylov::Complexquad::getArea() const
{
  return t1_.getArea() + t2_.getArea() + t3_.getArea() + t4_.getArea();
}
krylov::rectangle_t krylov::Complexquad::getFrameRect() const
{
  double minX = std::min({t1_.getA().x, t2_.getA().x, t3_.getA().x, t4_.getA().x});
  double maxX = std::max({t1_.getA().x, t2_.getA().x, t3_.getA().x, t4_.getA().x});
  double maxY = std::max({t1_.getA().y, t2_.getA().y, t3_.getA().y, t4_.getA().y});
  double minY = std::min({t1_.getA().y, t2_.getA().y, t3_.getA().y, t4_.getA().y});
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

