#include "rectangle.hpp"
#include <stdexcept>
#include <algorithm>
#include "shape.hpp"
#include "base-types.hpp"

namespace abramov
{
  Rectangle::Rectangle(point_t p1, point_t p2)
  {
    if (p1.x >= p2.x || p1.y >= p2.y)
    {
      throw std::logic_error("Impossible to build a rectangle");
    }
    createCQs(p1, p2, cmplxqd1_, cmplxqd2_, cmplxqd3_, cmplxqd4_);
  }

  Rectangle::Rectangle(ComplexQuad cq1, ComplexQuad cq2, ComplexQuad cq3, ComplexQuad cq4):
    cmplxqd1_(cq1),
    cmplxqd2_(cq2),
    cmplxqd3_(cq3),
    cmplxqd4_(cq4)
  {}

  double Rectangle::getArea() const noexcept
  {
    return cmplxqd1_.getArea() + cmplxqd2_.getArea() + cmplxqd3_.getArea() + cmplxqd4_.getArea();
  }

  rectangle_t Rectangle::getFrameRect() const noexcept
  {
    const double width = cmplxqd4_.getD().x - cmplxqd1_.getA().x;
    double height = std::abs(cmplxqd4_.getD().y - cmplxqd1_.getA().y);
    if (height == 0)
    {
      height = cmplxqd1_.getB().y - cmplxqd1_.getA().y;
    }
    point_t pos;
    pos.x = (cmplxqd1_.getA().x + cmplxqd4_.getD().x) / 2;
    pos.y = (cmplxqd1_.getA().y + cmplxqd4_.getD().y) / 2;
    rectangle_t frame_rect{width, height, pos};
    return frame_rect;
  }

  void Rectangle::move(double dx, double dy)
  {
    cmplxqd1_.move(dx, dy);
    cmplxqd2_.move(dx, dy);
    cmplxqd3_.move(dx, dy);
    cmplxqd4_.move(dx, dy);
  }

  void Rectangle::move(point_t p)
  {
    const point_t center = getFrameRect().pos;
    const double dx = p.x - center.x;
    const double dy = p.y - center.y;
    move(dx, dy);
  }

  void Rectangle::scale(double k)
  {
    if (k <= 0)
    {
      throw std::logic_error("Wrong scale coef\n");
    }
    else
    {
      const double newWidth = (cmplxqd4_.getD().x - cmplxqd1_.getA().x) * k;
      double height = 0;
      const double dy = std::abs(cmplxqd4_.getD().y - cmplxqd1_.getA().y);
      if (dy == 0)
      {
        height = cmplxqd1_.getB().y - cmplxqd1_.getA().y;
      }
      else
      {
        height = dy;
      }
      const double newHeight = height * k;
      const point_t center = getFrameRect().pos;
      const double x2 = center.x + newWidth / 2;
      const double y2 = center.y + newHeight / 2;
      const double x1 = center.x - newWidth / 2;
      const double y1 = center.y - newHeight / 2;
      const point_t p1{x1, y1};
      const point_t p2{x2, y2};
      createCQs(p1, p2, cmplxqd1_, cmplxqd2_, cmplxqd3_, cmplxqd4_);
    }
  }

  Rectangle *Rectangle::clone() const
  {
    return new Rectangle(*this);
  }
}
