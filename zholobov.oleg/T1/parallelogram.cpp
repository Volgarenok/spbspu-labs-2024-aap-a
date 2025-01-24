#include "parallelogram.hpp"

#include <cmath>

zholobov::Parallelogram::Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3)
{
  pos_.x = (p1.x + p3.x) / 2.0;
  pos_.y = (p1.y + p3.y) / 2.0;
  p1_.x = p1.x - pos_.x;
  p1_.y = p1.y - pos_.y;
  p2_.x = p2.x - pos_.x;
  p2_.y = p2.y - pos_.y;
}

double zholobov::Parallelogram::getArea() const
{
  double base = 0.0;
  if (p1_.y == p2_.y) {
    base = p2_.x - p1_.x;
  } else {
    base = 2.0 * pos_.x - p2_.x - p1_.x;
  }
  return std::abs(base * p1_.y * 2.0);
}

zholobov::rectangle_t zholobov::Parallelogram::getFrameRect() const
{
  rectangle_t rect;
  rect.pos = pos_;
  rect.height = std::abs(p1_.y) * 2.0;
  rect.width = std::abs(p1_.x) * 2.0;
  return rect;
}

void zholobov::Parallelogram::move(point_t p)
{
  pos_ = p;
}

void zholobov::Parallelogram::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void zholobov::Parallelogram::scale(double k)
{
  p1_.x *= k;
  p1_.y *= k;
  p2_.x *= k;
  p2_.y *= k;
}
