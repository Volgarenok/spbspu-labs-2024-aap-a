#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace sharifullina
{
  class Circle : public Shape
  {
  public:
    Circle(point_t center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t center_ = {0.0, 0.0};
    double radius_ = 0.0;
  };
}

#endif
