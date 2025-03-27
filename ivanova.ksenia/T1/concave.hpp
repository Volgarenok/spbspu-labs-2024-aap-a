#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"

namespace ivanova
{
  class Concave : public Shape
  {
  public:
    Concave(point_t cnPoint1, point_t cnPoint2, point_t cnPoint3, point_t cnPoint4);

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double ratio) override;

  private:
    point_t cnPoint1_;
    point_t cnPoint2_;
    point_t cnPoint3_;
    point_t cnPoint4_;
  };
}

#endif
