#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"
#include "triangle.hpp"

namespace dribas
{
  class Concave final : public Shape
  {
  public:
    Concave(point_t a, point_t b, point_t c, point_t d);
    Shape* clone() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;

  private:
    Triangle a_;
    Triangle b_;
    void scaleSilent(double ratio) override;
  };
}
#endif
