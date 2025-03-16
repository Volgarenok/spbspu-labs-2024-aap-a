#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <istream>
#include <cmath>
#include "base-types.hpp"

namespace shramko
{
  class Shape
  {
  protected:
      double distance(point_t p1, point_t p2)
      {
          return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
      }
      point_t center_;
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point)
    {
        double xMove = point.x - center_.x;
        double yMove = point.y - center_.y;
        this->move(xMove, yMove);
    }
    virtual void move(double x, double y) = 0;
    virtual void scale(double k) = 0;
    virtual ~Shape() = default;
  };
}

#endif
