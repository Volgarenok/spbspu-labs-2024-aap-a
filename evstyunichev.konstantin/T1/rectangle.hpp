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
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double, double);
    void move(point_t);
    void scale(double k);
    private:
      point_t find_mid() const;
      point_t leftDown_, rightUp_;
  };
}
#endif
