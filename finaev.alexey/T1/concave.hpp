#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"
#include "rectangle.hpp"

namespace finaev
{
  class Concave final: public Shape
  {
  public:
    Concave(point_t f, point_t s, point_t t, point_t i);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(double sx, double sy) override;
    void scale(double k) override;
  private:
    Rectangle first_;
    Rectangle second_;
    double first_area_;
    double second_area_;
  };
}

#endif
