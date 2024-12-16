#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace sveshnikov
{
  class Rectangle : public Shape
  {
    virtual double getArea() const override = 0;
    virtual rectangle_t getFrameRect() const override = 0;
    virtual void move(point_t p) override;
    virtual void move(double dx, double dy) override;
    virtual void scale(double k) override;
  };
}

#endif
