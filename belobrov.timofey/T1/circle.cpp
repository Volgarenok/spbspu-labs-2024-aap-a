#include "circle.hpp"

namespace belobrov
{
  Circle::Circle(double x, double y, double radius)
    : center_{x, y}, radius_(radius)
  {
    if (radius_ <= 0) {
      throw std::invalid_argument("Radius must be positive");
    }
  }

  double Circle::getArea() const
  {
    return M_PI * radius_ * radius_;
  }

  rectangle_t Circle::getFrameRect() const
  {
    return { 2 * radius_, 2 * radius_, center_ };
  }

  void Circle::move(const point_t& point)
  {
    center_ = point;
  }

  void Circle::move(double dx, double dy)
  {
    center_.x += dx;
    center_.y += dy;
  }

  void Circle::scale(double k)
  {
    if (k <= 0) {
      throw std::invalid_argument("Scaling factor must be positive");
    }
    radius_ *= k;
  }
}
