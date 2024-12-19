#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace duhanina
{
  class Circle : public Shape {
  public:
    Circle(point_t center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t pos_;
    double radius_;
  };
}

#endif
