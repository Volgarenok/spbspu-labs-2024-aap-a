#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"
nikonov::point_t getCenterOfGravity(const nikonov::point_t &A, const nikonov::point_t &B, const nikonov::point_t &C)
{
  return nikonov::point_t({ (A.x + B.x + C.x) / 3, ((A.y + B.y + C.y) / 3) });
}
double nikonov::getSegmentLength(const point_t &a, const point_t &b)
{
  return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
}
void scaleTrianglePoint(nikonov::point_t &pt, nikonov::point_t &center, double k)
{
  pt.x = center.x + (pt.x - center.x) * k;
  pt.y = center.y + (pt.y - center.y) * k;
}

nikonov::Triangle::Triangle(const point_t &a, const point_t &b, const point_t &c):
  a_(a),
  b_(b),
  c_(c)
{
  double ab = getSegmentLength(a, b);
  double bc = getSegmentLength(b, c);
  double ca = getSegmentLength(c, a);
  if (!((ab + bc > ca) && (ab + ca > bc) && (ca + bc > ab)))
  {
    throw std::logic_error("ERROR:noncorrect triangle parameters");
  }
}
double nikonov::Triangle::getArea() const
{
  rectangle_t tempRect = getFrameRect();
  return (tempRect.height * tempRect.width) / 2;
}
nikonov::rectangle_t nikonov::Triangle::getFrameRect() const
{
  double maxX = std::max(std::max(a_.x, b_.x), c_.x);
  double maxY = std::max(std::max(a_.y, b_.y), c_.y);
  double minX = std::min(std::min(a_.x, b_.x), c_.x);
  double minY = std::min(std::min(a_.y, b_.y), c_.y);
  double width = maxX - minX;
  double height = maxY - minY;
  point_t pos = point_t({ minX + (width / 2), minY + (height / 2) });
  return rectangle_t({ width, height, pos });
}
void nikonov::Triangle::move(const point_t &newPos)
{
  point_t center = getCenterOfGravity(a_, b_, c_);
  double diffX = newPos.x - center.x;
  double diffY = newPos.y - center.y;
  move(diffX, diffY);
}
void nikonov::Triangle::move(double x, double y)
{
  movePoint(a_, x, y);
  movePoint(b_, x, y);
  movePoint(c_, x, y);
}
void nikonov::Triangle::doScale(double k)
{
  point_t center = getCenterOfGravity(a_, b_, c_);
  scaleTrianglePoint(a_, center, k);
  scaleTrianglePoint(b_, center, k);
  scaleTrianglePoint(c_, center, k);
}
