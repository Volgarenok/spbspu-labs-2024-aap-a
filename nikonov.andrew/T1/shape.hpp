#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace nikonov
{
  struct Shape
  {
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &a) = 0;
    virtual void move(double x, double y) = 0;
    void scale(double k);
    virtual ~Shape() = default;
  private:
    virtual void doScale(double k) = 0;
  };
}
#endif
