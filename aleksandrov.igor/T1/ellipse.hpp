#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace aleksandrov
{
  class Ellipse: public Shape
  {
  public:
    Ellipse(const point_t& center, double vr, double hr);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& centerPoint) override;
    void move(double dx, double dy) override;
    void unsafeScale(double k) override;
  private:
    point_t center_;
    double vr_;
    double hr_;
  };
}

#endif

