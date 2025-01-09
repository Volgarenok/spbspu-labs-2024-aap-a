#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace zakirov
{
  class Circle final: public Shape
  {
  public:
    Circle(point_t center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t target) override;
    void move(double bias_x, double bias_y) override;
    void scale(double k) override;
  private:
    point_t center_;
    double radius_;
  };
}

#endif
