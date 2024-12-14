#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"

namespace maslov
{
  struct Regular : public Shape
  {
    Regular(point_t first, point_t second, point_t third):
    firstPoint_(first),
    secondPoint_(second), 
    thirdPoint_(third) {};
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
   private:
    point_t firstPoint_ = {0, 0};
    point_t secondPoint_ = {0, 0};
    point_t thirdPoint_ = {0, 0};
  };
}

#endif