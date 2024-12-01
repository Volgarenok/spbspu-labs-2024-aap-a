#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

struct Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  virtual rectangle_t move(point_t pnt) = 0;
  virtual rectangle_t move(double dx, double dy) = 0;
  virtual rectangle_t scale(double k) = 0;
};

#endif
