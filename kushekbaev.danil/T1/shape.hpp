#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cstddef>
#include <stdexcept>
#include "base-types.hpp"

namespace kushekbaev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t scalePoint) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double scaleCoeff) = 0;
    void scaleEverything(point_t scalePoint, double scaleCoeff);
    virtual Shape* clone() const noexcept = 0;
  };
}

#endif
