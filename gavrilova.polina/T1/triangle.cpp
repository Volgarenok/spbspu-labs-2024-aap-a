#include "triangle.hpp"
#include "pointManip.hpp"

namespace {
  bool isTriangle(gavrilova::point_t a, gavrilova::point_t b, gavrilova::point_t c) noexcept
  {
    double ab = gavrilova::getDistance(a, b);
    double bc = gavrilova::getDistance(b, c);
    double ac = gavrilova::getDistance(a, c);
    return ((ab + bc) > ac && (ab + ac) > bc && (ac + bc) > ab && ab && ac && bc);
  }
}

gavrilova::Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c):
  a_(a),
  b_(b),
  c_(c)
{
  if (!isTriangle(a, b, c)) {
    throw std::logic_error("Invalid arguments for triangle");
  }
}

double gavrilova::Triangle::getArea() const
{
  return std::abs(((a_.x * (b_.y - c_.y) +  b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y))) / 2.0);
}

gavrilova::rectangle_t gavrilova::Triangle::getFrameRect() const
{
  double minX = std::min(std::min(a_.x, b_.x), c_.x);
  double maxX = std::max(std::max(a_.x, b_.x), c_.x);
  double minY = std::min(std::min(a_.y, b_.y), c_.y);
  double maxY = std::max(std::max(a_.y, b_.y), c_.y);
  double height = maxY - minY;
  double width = maxX- minX;
  point_t pos {(maxX - minX) / 2 + minX, (maxY - minY) / 2 + minY};
  return {width, height, pos};
}

void gavrilova::Triangle::move(const point_t& p)
{
  point_t center = getFrameRect().pos;
  double difX = p.x - center.x;
  double difY = p.y - center.y;
  move(difX, difY);
}

void gavrilova::Triangle::move(double difX, double difY)
{
  movePoint(a_, difX, difY);
  movePoint(b_, difX, difY);
  movePoint(c_, difX, difY);
}

void gavrilova::Triangle::scaleWithoutCheck(double k) noexcept
{
  point_t center = getFrameRect().pos;
  scaleDistance(a_, center, k);
  scaleDistance(b_, center, k);
  scaleDistance(c_, center, k);
}
gavrilova::Shape* gavrilova::Triangle::clone() const
{
  return new Triangle(*this);
}

