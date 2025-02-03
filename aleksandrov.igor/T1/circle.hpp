#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"
#include "ellipse.hpp"

namespace aleksandrov
{
  class Circle final: public Shape
  {
  public:
    Circle(const point_t& center, double r);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& centerPoint) override;
    void move(double dx, double dy) override;
    void unsafeScale(double k) override;
  private:
    Ellipse ellipse_;
  };
}

#endif

