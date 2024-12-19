#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"

namespace sveshnikov
{
  class Ring : public Shape
  {
  private:
    point_t center_;
    double short_radius_;
    double long_radius_;

  public:
    Ring(point_t center, double short_radius, double long_radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  };
}

#endif
