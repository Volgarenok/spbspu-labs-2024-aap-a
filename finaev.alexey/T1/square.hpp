#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

namespace finaev
{
  class Square :public Shape
  {
  private:
    point_t leftDown;
    double side;
  public:
    Square(point_t l, double s);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(double sx, double sy) override;
    void scale(double k) override;
  };
}

#endif
