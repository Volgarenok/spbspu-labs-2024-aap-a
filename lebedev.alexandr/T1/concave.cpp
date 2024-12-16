#include "concave.hpp"
#include <cmath>
#include "base-types.hpp"

namespace lebedev
{
  double max(double a, double b, double c);
  double min(double a, double b, double c);
  double triangleArea(point_t p1, point_t p2, point_t p3);
}

lebedev::Concave::Concave(point_t p1, point_t p2, point_t p3, point_t p4) :
  p1_(p1), p2_(p2), p3_(p3), p4_(p4)
{}

double lebedev::Concave::getArea() const
{
  double s1 = lebedev::triangleArea(p1_, p2_, p3_);
  double s2 = lebedev::triangleArea(p2_, p3_, p4_);
  return s1 - s2;
}

lebedev::rectangle_t lebedev::Concave::getFrameRect() const
{
  lebedev::rectangle_t rect;
  rect.width = lebedev::max(p1_.x, p2_.x, p3_.x) - lebedev::min(p1_.x, p2_.x, p3_.x);
  rect.height = lebedev::max(p1_.y, p2_.y, p3_.y) - lebedev::min(p1_.y, p2_.y, p3_.y);
  rect.pos.x = lebedev::min(p1_.x, p2_.x, p3_.x) + rect.width / 2;
  rect.pos.y = lebedev::min(p1_.y, p2_.y, p3_.y) + rect.height / 2;
  return rect;
}

void lebedev::Concave::move(point_t p)
{
  double dx = p.x - p4_.x;
  double dy = p.y - p4_.y;
  p4_ = p;
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
}

void lebedev::Concave::move(double dx, double dy)
{
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
  p4_.x += dx;
  p4_.y += dy;
}

void lebedev::Concave::scale(double k)
{
  p1_.x = p4_.x + (p4_.x - p1_.x) * k;
  p1_.y = p4_.y + (p4_.y - p1_.y) * k;
  p2_.x = p4_.x + (p4_.x - p2_.x) * k;
  p2_.y = p4_.y + (p4_.y - p2_.y) * k;
  p3_.x = p4_.x + (p4_.x - p3_.x) * k;
  p3_.y = p4_.y + (p4_.y - p3_.y) * k;
}

double lebedev::max(double a, double b, double c)
{
  double d = std::fmax(a, b);
  return std::fmax(d, c);
}

double lebedev::min(double a, double b, double c)
{
  double d = std::fmin(a, b);
  return std::fmin(d, c);
}

double lebedev::triangleArea(point_t p1, point_t p2, point_t p3)
{
  return 0.5 * std::fabs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}
