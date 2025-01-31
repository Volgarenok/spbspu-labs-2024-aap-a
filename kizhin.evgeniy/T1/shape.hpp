#ifndef KIZHIN_T1_SHAPE_HPP
#define KIZHIN_T1_SHAPE_HPP

#include "base-types.hpp"

namespace kizhin {
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual rectangle_t getFrameRect() const = 0;
    virtual double getArea() const = 0;
    virtual Shape* clone() const = 0;

    virtual void move(const point_t&) = 0;
    virtual void move(double, double) = 0;
    virtual void unsafeScale(double) = 0;

    void scale(double);
  };
}

#endif

