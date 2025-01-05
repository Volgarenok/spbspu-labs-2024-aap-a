#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace komarova
{
  struct Triangle : public Shape
  {
  public:
    Triangle(point_t a, point_t b, point_t c);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t point) override;
    void scale(double coef) override;
  private:
    point_t a_, b_, c_;
  };
}

#endif
