#ifndef COMPLEXQUAD_H
#define COMPLEXQUAD_H

#include "shape.hpp"

namespace ivanova
{
  class Complexquad : public Shape
  {
  public:
    Complexquad(point_t point1, point_t point2, point_t point3, point_t point4);

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double ratio) override;

  private:
    point_t point1_;
    point_t point2_;
    point_t point3_;
    point_t point4_;
    point_t center;
  };
}

#endif
