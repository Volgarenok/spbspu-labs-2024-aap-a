#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace maslov
{
  struct Parallelogram : public Shape
  {
    Parallelogram(point_t first, point_t second, point_t third):
    first_(first), second_(second), third_(third),
    fourth_({first.x + third.x - second.x, first.y + third.y - second.y}) {};
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
   private:
    point_t first_ = {0, 0};
    point_t second_ = {0, 0};
    point_t third_ = {0, 0};
    point_t fourth_ = {0, 0};
  };
}

#endif