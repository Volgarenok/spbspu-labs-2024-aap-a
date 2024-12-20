#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
namespace evstyunichev
{
  struct Rectangle: public Shape
  {
    Rectangle(point_t, point_t);
    double getArea();
    rectangle_t getFrameRect();
    void move(double, double);
    void move(point_t);
    void scale(double k);
    point_t find_mid();
    private:
    point_t leftDown_, rightUp_;
  };
}
#endif
