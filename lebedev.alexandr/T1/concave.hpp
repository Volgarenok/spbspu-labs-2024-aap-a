#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"

namespace lebedev
{
  class Concave: public Shape
  {
  public:
    Concave(point_t p1, point_t p2, point_t p3, point_t p4);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
    point_t p4_;
  };
  double max(double a, double b, double c);
  double min(double a, double b, double c);
  double triangleArea(point_t p1, point_t p2, point_t p3);
}
#endif
