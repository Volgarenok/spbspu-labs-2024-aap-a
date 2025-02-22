#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace maslevtsov
{
  struct Rectangle final: public Shape
  {
  public:
    Rectangle(point_t bottomLeft, point_t topRight);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t pnt) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double k) override;
    void unsafeScale(double k) noexcept override;

  private:
    point_t bottomLeft_, topRight_;
  };
}

#endif
