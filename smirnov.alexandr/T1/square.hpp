#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"

namespace smirnov
{
  class Square : public Shape
  {
  private:
    point_t lowerLeft;
    double sideLength;
  public:
    Square(double x, double y, double length);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  };
}
#endif
