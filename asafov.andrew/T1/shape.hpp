#pragma once
#include "base-types.hpp"
class Shape
{
public:
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(point_t pos) = 0;
  virtual void move(double x, double y) = 0;
  virtual void scale(point_t pos, double scale) = 0;
  virtual ~Shape() = default;
};
