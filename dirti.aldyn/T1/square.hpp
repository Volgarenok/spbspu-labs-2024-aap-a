#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"
#include "rectangle.hpp"

namespace dirti
{
  struct Square final: public Shape
  {
  public:
    Square(point_t left_low, double length);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scaleUnsafe(double koef) override;
  private:
    Rectangle rectangle;
  };
}

#endif
