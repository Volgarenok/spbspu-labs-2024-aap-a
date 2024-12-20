#ifndef RING_HPP
#define RING_HPP
#include <iostream>
#include "base-types.hpp"
#include "circle.hpp"
#include "shape.hpp"
namespace evstyunichev
{
  struct Ring: public Shape
  {
    Ring(point_t, double, double);
    double getArea();
    rectangle_t getFrameRect();
    void move(double, double);
    void move(point_t);
    void scale(double);
    private:
      point_t mid_;
      double R_, r_;
  };
}
#endif
