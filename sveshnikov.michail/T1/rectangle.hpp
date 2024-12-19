#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace sveshnikov
{
  class Rectangle : public Shape
  {
  private:
    point_t low_left_;
    point_t up_right_;

  public:
    Rectangle(point_t low_left, point_t up_right);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  };
}

#endif
