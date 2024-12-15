#include "parallelogram.h"
#include <stdexcept>
#include <cmath>
namespace cherkasov
{
  Parallelogram::Parallelogram(point_t point1, point_t point2, point_t point3):
  point1_(point1),
  point2_(point2),
  point3_(point3)
  {
    if (point1.y != point2.y)
    {
      throw std::logic_error("One side must be parallel to the X");
    }
    calculateCenter();
  }
  void Parallelogram::calculateCenter()
  {
    length_ = std::abs(point2_.x - point1_.x);
    height_ = std::abs(point3_.y - point1_.y);
    center_.x = (point1_.x + point2_.x + point3_.x + (point3_.x - point1_.x)) / 4;
    center_.y = (point1_.y + point2_.y + point3_.y + (point3_.y - point2_.y)) / 4;
  }
  double Parallelogram::getArea() const
  {
    return length_ * height_;
  }

  rectangle_t Parallelogram::getFrameRect() const
  {
    return {length_, height_, center_};
  }
  void Parallelogram::move(point_t c)
  {
    double dx = c.x - center_.x;
    double dy = c.y - center_.y;
    point1_.x += dx;
    point1_.y += dy;
    point2_.x += dx;
    point2_.y += dy;
    point3_.x += dx;
    point3_.y += dy;
    center_ = c;
  }
  void Parallelogram::move(double dx, double dy)
  {
    point1_.x += dx;
    point1_.y += dy;
    point2_.x += dx;
    point2_.y += dy;
    point3_.x += dx;
    point3_.y += dy;
    center_.x += dx;
    center_.y += dy;
  }
  void Parallelogram::scale(double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("Scale factor must be positive");
    }
    point1_.x = center_.x + (point1_.x - center_.x) * k;
    point1_.y = center_.y + (point1_.y - center_.y) * k;
    point2_.x = center_.x + (point2_.x - center_.x) * k;
    point2_.y = center_.y + (point2_.y - center_.y) * k;
    point3_.x = center_.x + (point3_.x - center_.x) * k;
    point3_.y = center_.y + (point3_.y - center_.y) * k;
    calculateCenter();
  }
}
