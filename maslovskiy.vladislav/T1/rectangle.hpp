#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace maslovskiy
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(double x1, double y1, double x2, double y2);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t leftCorner_;
    point_t rightCorner_;
  };
}

#endif
