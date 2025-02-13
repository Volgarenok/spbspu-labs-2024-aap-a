#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"
namespace asafov
{
  class Ring : public Shape
  {
    point_t center;
    double innerradius;
    double outerradius;
  public:
    Ring(point_t pos, double radi, double rado);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double scale);
  };
}
#endif
