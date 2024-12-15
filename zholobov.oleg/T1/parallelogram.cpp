#include "parallelogram.hpp"

zholobov::Parallelogram::Parallelogram():
  pos_{},
  p1_{},
  p2_{}
{}

zholobov::Parallelogram::Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3):
  p1_(p1),
  p2_(p2)
{
  pos_.x = (p2.x + p3.x) / 2.0f;
  pos_.y = (p2.y + p3.y) / 2.0f;
}

double zholobov::Parallelogram::getArea()
{
  return (p2_.x - p1_.x) * (pos_.y - p1_.y) * 2.0f;
}

zholobov::rectangle_t zholobov::Parallelogram::getFrameRect()
{
  rectangle_t rect;
  rect.pos = pos_;
  rect.height = (pos_.y - p1_.y) * 2.0f;
  rect.width = (pos_.x - p1_.x) * 2.0f;
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
  p1_.x = (p1_.x - pos_.x) * k + pos_.x;
  p1_.y = (p1_.y - pos_.y) * k + pos_.y;
  p2_.x = (p2_.x - pos_.x) * k + pos_.x;
  p2_.y = (p2_.y - pos_.y) * k + pos_.y;
}
