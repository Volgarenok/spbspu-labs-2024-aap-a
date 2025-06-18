#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace shramko
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    void move(const point_t point)
    {
      double xMove = point.x - center_.x;
      double yMove = point.y - center_.y;
      this->move(xMove, yMove);
    }
    virtual void move(double x, double y) = 0;
    void scale(double k)
    {
      if (k <= 0)
      {
        throw std::invalid_argument("Scale must be positive!");
      }
      doScale(k);
    }
    virtual ~Shape() = default;
  protected:
    point_t center_;
    virtual void doScale(double k) = 0;
  };
}

#endif
