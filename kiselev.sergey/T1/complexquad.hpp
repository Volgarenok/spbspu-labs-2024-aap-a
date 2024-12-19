#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"
namespace kiselev
{
  class Complexquad : public Shape
  {
  public:
    Complexquad(point_t p1, point_t p2, point_t p3, point_t p4);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t a);
    void move(double dx, double dy);
    void scale(double k);

  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
    point_t p4_;
  };
}
#endif
