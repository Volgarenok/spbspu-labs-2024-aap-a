#include "concave.hpp"
#include <cmath>
#include "base-types.hpp"
#include "makeObjects.hpp"

namespace finaev
{
  double max(double a, double b, double c);
  double min(double a, double b, double c);
}
finaev::Concave::Concave(point_t f, point_t s, point_t t, point_t i) :
  first(f), second(s), third(t), internal(i)
{
}
double finaev::Concave::getArea() const
{
  double a1 = len(first, second);
  double b1 = len(second, third);
  double c = len(third, first);
  double p1 = (a1 + b1 + c) / 2;
  double s1 = std::sqrt(p1 * (p1 - a1) * (p1 - b1) * (p1 - c));
  double a2 = len(first, internal);
  double b2 = len(third, internal);
  double p2 = (a2 + b2 + c) / 2;
  double s2 = std::sqrt(p2 * (p2 - a2) * (p2 - b2) * (p2 - c));
  return s1 - s2;
}
double finaev::max(double a, double b, double c)
{
  double m = std::max(a, b);
  return std::max(m, c);
}
double finaev::min(double a, double b, double c)
{
  double m = std::min(a, b);
  return std::min(m, c);
}
finaev::rectangle_t finaev::Concave::getFrameRect() const
{
  rectangle_t a;
  a.pos = internal;
  a.width = max(first.x, second.x, third.x) - min(first.x, second.x, third.x);
  a.height = max(first.y, second.y, third.y) - min(first.y, second.y, third.y);
  return a;
}
void finaev::Concave::move(point_t a)
{
  first.x = a.x - (internal.x - first.x);
  first.y = a.y - (internal.x - first.x);
  second.x = a.x - (internal.x - second.x);
  second.y = a.y - (internal.y - second.y);
  third.x = a.x - (internal.x - third.x);
  third.y = a.y - (internal.y - third.y);
  internal.x = a.x;
  internal.y = a.y;
}
void finaev::Concave::move(double sx, double sy)
{
  first.x += sx;
  first.y += sy;
  second.x += sx;
  second.y += sy;
  third.x += sx;
  third.y += sy;
  internal.x += sx;
  internal.y += sy;
}
void finaev::Concave::scale(double k)
{
  first.x = (first.x - internal.x) * k + internal.x;
  first.y = (first.y - internal.y) * k + internal.y;
  second.x = (second.x - internal.x) * k + internal.x;
  second.y = (second.y - internal.y) * k + internal.y;
  third.x = (third.x - internal.x) * k + internal.x;
  third.y = (third.y - internal.y) * k + internal.y;
}
