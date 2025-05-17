#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include "shape.hpp"
#include "triangle.hpp"

namespace shramko
{
  class Complexquad final: public Shape
  {
  public:
    Complexquad(point_t a, point_t b, point_t c, point_t d);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double x, double y) override;
  private:
    Triangle t1_, t2_, t3_, t4_;
    point_t points_[4];
    void doScale(double k) override;
    bool isConvex() const;
  };
}

#endif