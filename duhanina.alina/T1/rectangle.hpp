#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace duhanina
{
  class Rectangle : public Shape {
  public:
    Rectangle(point_t lt, point_t rt);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t lt_;
    point_t rt_;
  };
}

#endif
