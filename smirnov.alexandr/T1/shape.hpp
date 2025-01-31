#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace smirnov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t p) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
  protected:
    void applyMove(point_t & point, double dx, double dy) const
    {
      point.x += dx;
      point.y += dy;
    }
    void applyScale(point_t & point, const point_t & center, double k) const
    {
      point.x = center.x + (point.x - center.x) * k;
      point.y = center.y + (point.y - center.y) * k;
    }
  };
}
#endif
