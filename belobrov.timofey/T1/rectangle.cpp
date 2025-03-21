#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

namespace belobrov
{
  Rectangle::Rectangle(double x1, double y1, double x2, double y2)
    : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {
    if (x1_ >= x2_ || y1_ >= y2_) {
      throw std::invalid_argument("Invalid rectangle coordinates");
    }
  }

  double Rectangle::getArea() const
  {
    return std::abs((x2_ - x1_) * (y2_ - y1_));
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    double width = std::abs(x2_ - x1_);
    double height = std::abs(y2_ - y1_);
    point_t center = { (x1_ + x2_) / 2, (y1_ + y2_) / 2 };
    return {width, height, center};
  }

  void Rectangle::move(const point_t& newPos)
  {
    double centerX = (x1_ + x2_) / 2.0;
    double centerY = (y1_ + y2_) / 2.0;
    double dx = newPos.x - centerX;
    double dy = newPos.y - centerY;
    move(dx, dy);
  }

  void Rectangle::move(double dx, double dy)
  {
    x1_ += dx;
    y1_ += dy;
    x2_ += dx;
    y2_ += dy;
  }

  void Rectangle::scale(double k)
  {
    if (k <= 0) {
      throw std::invalid_argument("Scaling factor must be positive");
    }
    double centerX = (x1_ + x2_) / 2.0;
    double centerY = (y1_ + y2_) / 2.0;

    x1_ = centerX + (x1_ - centerX) * k;
    y1_ = centerY + (y1_ - centerY) * k;
    x2_ = centerX + (x2_ - centerX) * k;
    y2_ = centerY + (y2_ - centerY) * k;
  }
}
