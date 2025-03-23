#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace lebedev
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t leftDown, point_t rightUp);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t leftDown_;
    point_t rightUp_;
  };
}
#endif
