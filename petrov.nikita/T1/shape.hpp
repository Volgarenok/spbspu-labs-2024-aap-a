#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace petrov
{
  struct Shape
  {
    virtual double getArea() const = 0;
    virtual petrov::rectangle_t getFrameRect() const = 0;
    virtual void move(petrov::point_t concrete_point) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
    virtual ~Shape() = default;
  };
}
#endif
