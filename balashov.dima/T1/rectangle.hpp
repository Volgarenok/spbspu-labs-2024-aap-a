#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace balashov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(double xLeft, double yUp, double xRight, double yDowm);
    virtual rectangle_t getFrameRect() const override;
    double getArea() const override;
    void move(point_t target) override;
    void move(double x, double y) override;
    void scale(double scaleCoefficient) override;
  private:
    point_t angleDownLeft;
    point_t angleUpRight;
    point_t сentre;
  };
}
#endif
