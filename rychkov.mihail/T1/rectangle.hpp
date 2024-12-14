#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace rychkov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle() = delete;
    Rectangle(point_t center, double height, double width);
    Rectangle(point_t bottomLeft, point_t topRight);

    virtual double getArea() const noexcept override;
    virtual rectangle_t getFrameRect() const noexcept override;
    virtual void move(point_t destination) noexcept override;
    virtual void move(double deltaX, double deltaY) noexcept override;
    virtual void scale(double coef) override;
  private:
    point_t center_;
    double height_, width_;
  };
}

#endif
