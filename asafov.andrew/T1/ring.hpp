#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"
namespace asafov
{
  class Ring final: public Shape
  {
  public:
    Ring(point_t center, double innerradius, double outerradius);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double dx, double dy);
    void doUnsafeScale(double k);
  private:
    point_t center_;
    double innerradius_;
    double outerradius_;
  };
}
#endif
