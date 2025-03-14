#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

namespace dribas
{
  class Triangle final: public Shape
  {
  public:
    Triangle(point_t a, point_t b, point_t c);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    Shape* clone() const override;

  private:
    point_t a_;
    point_t b_;
    point_t c_;
    void scaleSilent(double ratio) override;
  };
}
#endif
