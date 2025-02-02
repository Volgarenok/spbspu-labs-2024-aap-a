#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"
#include "circle.hpp"

namespace sharifullina
{
  class Ring final: public Shape
  {
  public:
    Ring(point_t center, double inRadius, double outRadius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    Circle inner_;
    Circle outer_;
  };
}

#endif
