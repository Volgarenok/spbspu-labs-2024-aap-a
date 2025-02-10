#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"
#include "rectangle.hpp"

namespace finaev
{
  class Square final: public Shape
  {
  public:
    Square(point_t l, double s);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(double sx, double sy) override;
    void scale(double k) override;
  private:
    Rectangle rect_;
  };
}

#endif
