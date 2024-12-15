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
    double getArea() override;
    point_t getCentre();
    rectangle_t getFrameRect() override;
    void move(point_t a) override;
    void move(double sx, double sy) override;
    void scale(double k) override;
  };
}

#endif
