#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <cmath>

namespace belobrov
{
  class Circle : public Shape
  {
  public:
    Circle(double x, double y, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t center_;
    double radius_;
  };
}

#endif

