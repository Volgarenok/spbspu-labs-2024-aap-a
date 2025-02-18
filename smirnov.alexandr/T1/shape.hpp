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
    virtual void unsafeScale(double k) noexcept = 0;
    void scale(double k);
  protected:
    void applyMove(point_t & point, double dx, double dy);
    void applyScale(point_t & point, const point_t & center, double k);
  };
}
#endif
