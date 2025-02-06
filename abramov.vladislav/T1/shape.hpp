#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace abramov
{
  struct Shape
  {
    virtual double getArea() const noexcept = 0;
    virtual rectangle_t getFrameRect() const noexcept = 0;
    virtual void move(const point_t &p) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
    virtual ~Shape() = default;
    virtual Shape *clone() const = 0;
    void scaleSafe(double k);
  };
}
#endif
