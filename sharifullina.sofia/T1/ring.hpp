#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"

namespace sharifullina
{
  class Ring : public Shape
  {
  public:
    Ring(point_t center, double inRadius, double outRadius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t center_;
    double outRadius_;
    double inRadius_;
  };
}

#endif
