#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace balashov
{
  class Circle : public Shape
  {
  public:
    Circle(point_t center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t target) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t centerPoint;
    double radiusCircle;
    };
}

#endif
