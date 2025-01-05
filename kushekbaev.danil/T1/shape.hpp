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
    void scaleEverything(point_t scalePoint, double scaleCoeff)
    {
      point_t beforeScale = getFrameRect().pos;
      move(scalePoint);
      point_t afterScale = getFrameRect().pos;
      point_t vector = { (afterScale.x - beforeScale.x) * scaleCoeff, (afterScale.y - beforeScale.y) * scaleCoeff };
      scale(scaleCoeff);
      move(-vector.x, -vector.y);
    }
  };

  double getLineLength(const point_t first, const point_t second);
  double getAreaOfTriangle(const point_t first, const point_t second, const point_t third);
}

#endif
