#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace maslov
{
  struct Rectangle : public Shape
  {
    Rectangle(point_t x, point_t y):
    lowerLeftCorner_(x), upperRightCorner_(y) {};
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double dx, double dy) override;
    //void scale(double k) override;
   private:
    point_t lowerLeftCorner_, upperRightCorner_;  
  };
}

#endif