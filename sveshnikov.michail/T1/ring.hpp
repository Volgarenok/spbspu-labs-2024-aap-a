#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"
#include "ellipse.hpp"

namespace sveshnikov
{
  class Ring final: public Shape
  {
  public:
    Ring(point_t center, double long_radius, double short_radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    Ellipse small_ellipse_;
    Ellipse big_ellipse_;
  };
}

#endif
