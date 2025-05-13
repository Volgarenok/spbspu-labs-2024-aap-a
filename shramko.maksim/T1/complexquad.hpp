#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include "shape.hpp"
#include "triangle.hpp"

namespace shramko
{
  class Complexquad final: public Shape
  {
  public:
    Complexquad(point_t p1, point_t p2, point_t p3, point_t p4);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double x, double y) override;

  private:
    point_t points_[4];
    void doScale(double k) override;
    void validateConvex() const;
  };
}

#endif
