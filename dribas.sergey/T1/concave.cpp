#include "concave.hpp"
#include <cmath>
#include <stdexcept>
#include "base-types.hpp"
#include "triangle.hpp"

bool isDupePoint(dribas::point_t p1, dribas::point_t p2, dribas::point_t p3, dribas::point_t p4) {
   if (p1.x == p2.x && p1.y == p2.y) return true;
   if (p1.x == p3.x && p1.y == p3.y) return true;
   if (p1.x == p4.x && p1.y == p4.y) return true;
   if (p2.x == p3.x && p2.y == p3.y) return true;
   if (p2.x == p4.x && p2.y == p4.y) return true;
   if (p3.x == p4.x && p3.y == p4.y) return true;
   return false;
}

bool isTriangle(dribas::point_t a, dribas::point_t b, dribas::point_t c)
{
  return !((((a.x == b.x) && (a.x == c.x))) || (( a.y == b.y) && (a.y == c.y)));
}

double getYourArea(dribas::point_t a, dribas::point_t b, dribas::point_t c) {
  return std::abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y -b.y)) / 2.0l);
}

bool isPointInTriangle(dribas::point_t a, dribas::point_t b, dribas::point_t c, dribas::point_t d)
{
  double s = getYourArea(a, b, c);
  double s1 = getYourArea(a, b, d);
  double s2 = getYourArea(a, d, c);
  double s3 = getYourArea(d, b, c);
  return (s == (s1 + s2 + s3));
}

dribas::Concave::Concave(dribas::point_t a, dribas::point_t b, dribas::point_t c, dribas::point_t d):
  a_(Triangle{a, b, c}),
  b_(Triangle{b, c, d})
{
  if (!isTriangle(d, b, c) || !isPointInTriangle(a, b, c, b) || isDupePoint(a, b, c, d)) {
    throw std::invalid_argument("Error witch point for concave\n");
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
