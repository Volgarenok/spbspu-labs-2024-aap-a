#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "shape.hpp"

namespace sharifullina
{
  class Ellipse: public Shape
  {
  public:
    Ellipse(point_t center, double radiusX, double radiusY);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scaleWithoutCheck(double k) override;
  private:
    point_t center_;
    double radiusX_;
    double radiusY_;
  };
}

#endif
