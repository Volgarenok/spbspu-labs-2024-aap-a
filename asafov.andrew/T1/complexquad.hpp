#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"
namespace asafov
{
  class Complexquad : public Shape
  {
    point_t one;
    point_t two;
    point_t three;
    point_t four;
  public:
    Complexquad(point_t a, point_t b, point_t c, point_t d);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double scale);
  };
}
#endif
