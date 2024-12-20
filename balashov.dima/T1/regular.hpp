#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"

namespace balashov
{
  class Regular : public Shape
  {
  public:
    Regular(point_t firstPoint_, point_t secondPoint_, point_t thirdPoint_);
    double getArea() const override;
    rectangle_t getFrameRect() const;
    void move(double x, double y) override;
    void move(point_t pointRoute) override;
    void scale(double scaleCoefficient) override;
  private:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
  };
}

#endif
