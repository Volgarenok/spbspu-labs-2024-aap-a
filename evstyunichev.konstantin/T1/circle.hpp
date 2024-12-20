#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
namespace evstyunichev
{
  struct Circle: public Shape
  {
    Circle(point_t, double);
    double getArea();
    rectangle_t getFrameRect();
    void move(double, double);
    void move(point_t);
    void scale(double k);
    private:
    point_t mid_;
    double r_;
  };
}
#endif
