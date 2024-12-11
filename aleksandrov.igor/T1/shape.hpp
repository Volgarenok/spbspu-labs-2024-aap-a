#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"
#include <cstddef>

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  // virtual void move(const point_t& centerPoint);
  // virtual void move(const double moveX, const double moveY);
  // virtual void scale(size_t k) = 0;
};

#endif

