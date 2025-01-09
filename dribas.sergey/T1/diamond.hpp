#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "triangle.hpp"

namespace dribas
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t a, point_t b, point_t c);
    double getArea() const  override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double ratio) override;
  private:
    Triangle a_;
    Triangle b_;
    Triangle c_;
    Triangle d_;
  };
}
#endif
