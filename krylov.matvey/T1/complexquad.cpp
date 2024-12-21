#include "complexquad.hpp"
#include "triangle.hpp"
#include <algorithm>
#include <stdexcept>

krylov::Complexquad::Complexquad(const point_t& a, const point_t& b, const point_t& c, const point_t& d):
a_(a), b_(b), c_(c), d_(d)
{}
krylov::point_t krylov::Complexquad::findIntersection(const point_t& a, const point_t& b, const point_t& c, const point_t& d) const
{
  double m1 = (b.y - a.y) / (b.x - a.x);
  double m2 = (d.y - c.y) / (d.x - c.x);
  double b1 = a.y - m1 * a.x;
  double b2 = c.y - m2 * c.x;
  return {(b2 - b1) / (m1 - m2), m1 * ((b2 - b1) / (m1 - m2)) + b1};
}
double krylov::Complexquad::getArea() const
{
  point_t intersectionPoint = findIntersection(a_, b_, c_, d_);
  krylov::Triangle firstTriangle(a_, d_, intersectionPoint);
  krylov::Triangle secondTriangle(intersectionPoint, b_, c_);
  double firstTriangleArea = firstTriangle.getArea();
  double secondTriangleArea = secondTriangle.getArea();
  return firstTriangleArea + secondTriangleArea;
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

