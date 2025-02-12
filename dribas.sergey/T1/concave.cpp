#include "concave.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"
#include "triangle.hpp"

namespace {
  bool isDupePoint(dribas::point_t p1, dribas::point_t p2, dribas::point_t p3, dribas::point_t p4)
  {
    return (p1.x == p2.x && p1.y == p2.y) ||
    (p1.x == p3.x && p1.y == p3.y) ||
    (p1.x == p4.x && p1.y == p4.y) ||
    (p2.x == p3.x && p2.y == p3.y) ||
    (p2.x == p4.x && p2.y == p4.y) ||
    (p3.x == p4.x && p3.y == p4.y);
  }

  bool isTriangle(dribas::point_t a, dribas::point_t b, dribas::point_t c)
  {
    return !(((a.x == b.x) && (a.x == c.x)) || (( a.y == b.y) && (a.y == c.y)));
  }

  double getTRinagleArea(dribas::point_t a, dribas::point_t b, dribas::point_t c)
  {
    return std::abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
  }

  bool isPointInTriangle(dribas::point_t a, dribas::point_t b, dribas::point_t c, dribas::point_t d)
  {
    double s = getTRinagleArea(a, b, c);
    double s1 = getTRinagleArea(a, b, d);
    double s2 = getTRinagleArea(a, d, c);
    double s3 = getTRinagleArea(d, b, c);
    return (s == (s1 + s2 + s3));
  }
}

dribas::Concave::Concave(dribas::point_t a, dribas::point_t b, dribas::point_t c, dribas::point_t d):
  a_(Triangle{a, b, c}),
  b_(Triangle{b, c, d})
{
  if (!isTriangle(d, b, c) || !isPointInTriangle(a, b, c, b) || isDupePoint(a, b, c, d)) {
    throw std::invalid_argument("Error witch point for concave");
  }
}

double dribas::Concave::getArea() const
{
  return a_.getArea() - b_.getArea();
}
dribas::rectangle_t dribas::Concave::getFrameRect() const
{
  return a_.getFrameRect();
}
void dribas::Concave::move(double x, double y)
{
  a_.move(x,y);
  b_.move(x,y);
}

void dribas::Concave::move(dribas::point_t point)
{
  a_.move(point);
  b_.move(point);
}

void dribas::Concave::scale(double ratio)
{
  if (ratio <= 0) {
    throw std::invalid_argument("under zero ratio\n");
  }
  a_.scale(ratio);
  b_.scale(ratio);
}
dribas::Shape* dribas::Concave::clone() const
{
  return new Concave(*this);
}
