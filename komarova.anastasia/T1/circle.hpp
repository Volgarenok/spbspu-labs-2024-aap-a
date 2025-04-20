#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace komarova
{
  struct Circle final: public Shape
  {
  public:
    Circle(point_t point_c, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t point) override;
    void unsafeScale(double coef) override;
  private:
    point_t point_c_;
    double radius_;
  };
}

#endif
