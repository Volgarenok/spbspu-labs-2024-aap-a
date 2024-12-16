#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace balashov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(double xLeft, double yUp, double xRight, double yDowm);
    rectangle_t getFrameRect() const override;
    double getArea() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t angleDownLeft_;
    point_t angleUpRight_;
    point_t сentre;
  };
}
#endif
