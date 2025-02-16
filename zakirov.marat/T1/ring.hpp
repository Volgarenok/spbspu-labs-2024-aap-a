#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"

namespace zakirov
{
  class Ring final: public Shape
  {
  public:
    Ring(const point_t & center, double ex_radius, double in_radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & target) override;
    void move(double bias_x, double bias_y) override;
    void scale(double k) noexcept override;
    Shape * clone() const override;
  private:
    point_t center_;
    double ex_radius_;
    double in_radius_;
  };
}

#endif
