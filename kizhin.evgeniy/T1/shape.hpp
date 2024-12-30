#ifndef KIZHIN_T1_SHAPE_HPP
#define KIZHIN_T1_SHAPE_HPP

#include "base-types.hpp"

namespace kizhin {
  class Shape;
}

class kizhin::Shape
{
public:
  virtual ~Shape() = default;

  virtual rectangle_t getFrameRect() const = 0;
  virtual double getArea() const = 0;

  virtual void move(const point_t&) = 0;
  virtual void move(double, double) = 0;
  virtual void scale(double) = 0;
};

#endif
