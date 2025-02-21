#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <memory>
#include "base-types.hpp"

namespace hismatova
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void move(const point_t& newPos) = 0;
    void scale_(double index);
    virtual void scale(double index) = 0;
  };
}

#endif
