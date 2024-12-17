#ifndef TRANGLE_HPP
#define TRANGLE_HPP

#include "shape.hpp"

namespace shramko
{
  class Triangle : public Shape
  {
  public:
    Triangle(point_t One, point_t Two, point_t Three);
    double getArea() const override;
    rectangle_t getRectangleFrame() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
    point_t getCentre();

  private:
    point_t One_;
    point_t Two_;
    point_t Three_;
  };
}

#endif


