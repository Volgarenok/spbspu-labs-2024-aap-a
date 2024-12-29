#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"

namespace ivanova
{
  class Concave : public Shape
  {
  public:
    Concave(point_t conPoint1, point_t conPoint2, point_t conPoint3, point_t conPoint4);

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double) override;

  private:
    point_t conPoint1_;
    point_t conPoint2_;
    point_t conPoint3_;
    point_t conPoint4_;
  };
}

#endif
