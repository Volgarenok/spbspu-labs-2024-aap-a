#include "parallelogram.hpp"

#include <cmath>

guseynov::Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3)
{
  pos_.x = (p1.x + p3.x) / 2.0;
  pos_.y = (p1.y + p3.y) / 2.0;
  p1_.x = p1.x - pos_.x;
  p1_.y = p1.y - pos_.y;
  p2_.x = p2.x - pos_.x;
  p2_.y = p2.y - pos_.y;
}

double guseynov::Parallelogram::getArea() const
{
  double res;
  if (p1_.y == p2_.y)
  {
    res = p2_.x - p1_.x;
  }
  else
  {
    res = 2.0 * pos_.x - p2_.x - p1_.x;
  }
  return std::fabs(res * p1_.y * 2.0);
}

guseynov::rectangle_t guseynov::Parallelogram::getFrameRect() const
{
  double height = std::fabs(p1_.y) * 2.0;
  double width = std::fabs(p1_.x) * 2.0;
  return {width, height, pos_};
}

void guseynov::Parallelogram::move(point_t p)
{
  pos_ = p;
}

void guseynov::Parallelogram::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}

void guseynov::Parallelogram::scale(double k)
{
  p1_.x *= k;
  p1_.y *= k;
  p2_.x *= k;
  p2_.y *= k;
}
