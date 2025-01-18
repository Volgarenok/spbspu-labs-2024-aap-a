#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cstddef>
#include "base-types.hpp"

namespace kushekbaev
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t a) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
    virtual ~Shape() = default;
    void scaleEverything(point_t scalePoint, double scaleCoeff);
  };

  double getLineLength(const point_t first, const point_t second);
  double getAreaOfTriangle(const point_t first, const point_t second, const point_t third);
}

#endif
