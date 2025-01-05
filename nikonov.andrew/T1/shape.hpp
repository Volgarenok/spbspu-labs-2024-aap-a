#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace nikonov
{
  struct Shape
  {
    virtual ~Shape() noexcept = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const noexcept = 0;
    virtual void move(const point_t &a) noexcept = 0;
    virtual void move(double x, double y) noexcept = 0;
    virtual void scale(double k) noexcept = 0;
    void scaleWithCheck(double k);
  };
}
#endif
