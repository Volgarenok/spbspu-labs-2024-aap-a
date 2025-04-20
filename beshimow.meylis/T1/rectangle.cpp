#include "rectangle.hpp"
#include <stdexcept>

namespace beshimow
{
  Rectangle::Rectangle(double width, double height, const point_t& pos)
    : width_(width), height_(height), pos_(pos)
  {
    if (width <= 0 || height <= 0)
    {
      throw std::invalid_argument("Width and height must be positive");
    }
  }

  double Rectangle::getArea() const
  {
    return width_ * height_;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return {width_, height_, pos_};
  }

  void Rectangle::move(const point_t& point)
  {
    pos_ = point;
  }

  void Rectangle::move(double dx, double dy)
  {
    pos_.x += dx;
    pos_.y += dy;
  }

  void Rectangle::scale(double factor)
  {
    if (factor <= 0)
    {
      throw std::invalid_argument("Scale factor must be positive");
    }
    width_ *= factor;
    height_ *= factor;
  }
}
