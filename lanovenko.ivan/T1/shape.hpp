#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace lanovenko
{
  class Shape
  {
  public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(point_t p) = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void unsafeScale(double k) = 0;
  void scale(double k);
  };
}

#endif
