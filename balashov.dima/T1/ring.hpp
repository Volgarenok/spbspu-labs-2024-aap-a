#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"

namespace balashov
{
  class Ring : public Shape
  {
  public:
    Ring(point_t center, double radiusIn, double radiusOut);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t target) override;
    void move(double x, double y) override;
    void scale(double scaleCoefficient) override;
  private:
    point_t centerPoint;
    double outerRadius;
    double innerRadius;
  };
}

#endif
