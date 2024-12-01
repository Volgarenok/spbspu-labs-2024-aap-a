#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

struct Rectangle: Shape
{
public:
  double getArea() override;
  rectangle_t getFrameRect() override;
  rectangle_t move(point_t pnt) override;
  rectangle_t move(double dx, double dy) override;
  rectangle_t scale(double k) override;

private:
  rectangle_t rect_;
};

#endif
