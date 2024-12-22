#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace shramko
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t leftBottom, point_t rightTop);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t leftBottom_;
    point_t rightTop_;
  };
}

#endif
