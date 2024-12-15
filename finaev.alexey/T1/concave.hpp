#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"

namespace finaev
{
  class Concave :public Shape
  {
  private:
    point_t first;
    point_t second;
    point_t third;
    point_t internal;
  public:
    Concave(point_t f, point_t s, point_t t, point_t i);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(double sx, double sy) override;
    void scale(double k) override;
  };
}

#endif
