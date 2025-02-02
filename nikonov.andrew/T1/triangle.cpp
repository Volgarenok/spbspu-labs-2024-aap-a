#include "triangle.hpp"
#include <stdexcept>
#include "additional-utilities.hpp"
namespace
{
  nikonov::point_t getCenterOfGravity(const nikonov::point_t &a, const nikonov::point_t &b, const nikonov::point_t &c) noexcept
  {
    return nikonov::point_t{ (a.x + b.x + c.x) / 3, ((a.y + b.y + c.y) / 3) };
  }
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
  point_t pos{ minX + (width / 2), minY + (height / 2) };
  return { width, height, pos };
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
void nikonov::Triangle::scale(double k) noexcept
{
  point_t center = getCenterOfGravity(a_, b_, c_);
  scalePoint(a_, center, k);
  scalePoint(b_, center, k);
  scalePoint(c_, center, k);
}
nikonov::Shape *nikonov::Triangle::clone() const
{
  return new Triangle{ a_, b_, c_ };
}
