#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"

namespace krylov
{
  class Ring final: public Shape
  {
  public:
    Ring(const point_t& center, double outerRadius, double innerRadius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void unsafeScale(double factor) noexcept override;
  private:
    point_t center_;
    double outerRadius_;
    double innerRadius_;
  };
}

#endif
