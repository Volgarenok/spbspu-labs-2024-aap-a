#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"
namespace bocharov
{
  class Concave final: public Shape
  {
  public:
    Concave(point_t a, point_t b, point_t c, point_t d);
    double getArea() const  override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double ratio) override;
  private:
    point_t a_;
    point_t b_;
    point_t c_;
    point_t d_;
  };
}
#endif
