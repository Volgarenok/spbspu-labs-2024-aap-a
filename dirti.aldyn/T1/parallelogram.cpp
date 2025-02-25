#include "parallelogram.hpp"
#include <cmath>

dirti::Parallelogram::Parallelogram(const point_t p1, const point_t p2, const point_t p3) :
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  if ((p1.y == p3.y) || !((p1.y == p2.y && p1.x != p2.x) || (p2.y == p3.y && p2.x != p3.x)))
  {
    throw std::logic_error("Wrong shape");
  }
  if (p2.y == p3.y)
  {
    p1_ = p3;
    p3_ = p1;
  }
}

double dirti::Parallelogram::getArea() const
{
  return std::abs(p1_.x - p2_.x) * std::abs(p2_.y - p3_.y);
}

dirti::rectangle_t dirti::Parallelogram::getFrameRect() const
{
  double width = std::abs(p1_.x - p2_.x) + std::abs(p2_.x - p3_.x);
  double height = std::abs(p3_.y - p2_.y);
  point_t pos{ p1_.x - (p1_.x - p3_.x) / 2, p1_.y - (p1_.y - p3_.y) / 2 };
  rectangle_t frameRect{ width, height, pos };
  return frameRect;
}

void dirti::Parallelogram::move(double x, double y)
{
  p1_ = { p1_.x + x, p1_.y + y };
  p2_ = { p2_.x + x, p2_.y + y };
  p3_ = { p3_.x + x, p3_.y + y };
}

void dirti::Parallelogram::move(point_t point)
{
  point_t pos_ = getFrameRect().pos;
  move(point.x - pos_.x, point.y - pos_.y);
}

void dirti::Parallelogram::scale(double koef)
{
  point_t pos_ = getFrameRect().pos;
  p1_ = { pos_.x - (pos_.x - p1_.x) * koef, pos_.y - (pos_.y - p1_.y) * koef };
  p2_ = { pos_.x - (pos_.x - p2_.x) * koef, pos_.y - (pos_.y - p2_.y) * koef };
  p3_ = { pos_.x - (pos_.x - p3_.x) * koef, pos_.y - (pos_.y - p3_.y) * koef };
}
