#include "parallelogram.hpp"
#include <cmath>

bocharov::Parallelogram::Parallelogram():
  pos_{},
  p1_{},
  p2_{}
{}

bocharov::Parallelogram::Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3)
{
  pos_.x = (p1.x + p3.x) / 2.0;
  pos_.y = (p1.y + p3.y) / 2.0;
  p1_.x = p1.x - pos_.x;
  p1_.y = p1.y - pos_.y;
  p2_.x = p2.x - pos_.x;
  p2_.y = p2.y - pos_.y;
}

double bocharov::Parallelogram::getArea() const
{
  double base = 0.0;
  if (p1_.y == p2_.y)
  {
    base = p2_.x - p1_.x;
  }
  else
  {
    base = 2.0 * pos_.x - p2_.x - p1_.x;
  }
  return std::abs(base * p1_.y * 2.0);
}

bocharov::rectangle_t bocharov::Parallelogram::getFrameRect() const
{
  rectangle_t rect;
  rect.pos = pos_;
  rect.height = std::abs(p1_.y) * 2.0;
  rect.width = std::abs(p1_.x) * 2.0;
  return rect;
}

void bocharov::Parallelogram::move(point_t p)
{
  pos_ = p;
}

void bocharov::Parallelogram::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void bocharov::Parallelogram::scale(double k)
{
  p1_.x *= k;
  p1_.y *= k;
  p2_.x *= k;
  p2_.y *= k;
}
