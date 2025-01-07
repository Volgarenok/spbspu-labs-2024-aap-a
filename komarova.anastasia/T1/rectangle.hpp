#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace komarova
{
  struct Rectangle: public Shape
  {
  public:
    Rectangle(point_t low_left, point_t up_right);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy);
    void move(point_t point) override;
    void scale(double coef) override;
  private:
    point_t low_left_;
    point_t up_right_;
  };
}

#endif
