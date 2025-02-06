#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <stdexcept>
#include "base-types.hpp"


namespace gavrilova {
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& p) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scaleWithoutCheck(double k) noexcept = 0;
    void scale(double k);
    virtual Shape* clone() const = 0;
  };
}
#endif
