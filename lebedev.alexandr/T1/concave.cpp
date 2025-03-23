#include "concave.hpp"
#include <algorithm>
#include <stdexcept>
#include "triangleOperations.hpp"
#include "base-types.hpp"

lebedev::Concave::Concave(point_t p1, point_t p2, point_t p3, point_t p4):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_(p4)
{
  if (!isTriangle(p1, p2, p3) || !isPointInsideTriangle(p1, p2, p3, p4))
  {
    throw std::invalid_argument("");
  }
}

double lebedev::Concave::getArea() const
{
  double s1 = triangleArea(p1_, p2_, p3_);
  double s2 = triangleArea(p2_, p3_, p4_);
  return s1 - s2;
}

lebedev::rectangle_t lebedev::Concave::getFrameRect() const
{
  double width = std::max({ p1_.x, p2_.x, p3_.x }) - std::min({ p1_.x, p2_.x, p3_.x });
  double height = std::max({ p1_.y, p2_.y, p3_.y }) - std::min({ p1_.y, p2_.y, p3_.y });
  double centreX = std::min({ p1_.x, p2_.x, p3_.x }) + width / 2;
  double centreY = std::min({ p1_.y, p2_.y, p3_.y }) + height / 2;
  return { width, height, { centreX, centreY } };
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

void lebedev::Concave::move(point_t p)
{
  move(p.x - p4_.x, p.y - p4_.y);
}

void lebedev::Concave::scale(double k)
{
  p1_.x = p4_.x + (p1_.x - p4_.x) * k;
  p1_.y = p4_.y + (p1_.y - p4_.y) * k;
  p2_.x = p4_.x + (p2_.x - p4_.x) * k;
  p2_.y = p4_.y + (p2_.y - p4_.y) * k;
  p3_.x = p4_.x + (p3_.x - p4_.x) * k;
  p3_.y = p4_.y + (p3_.y - p4_.y) * k;
}
