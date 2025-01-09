#ifndef SHAPE
#define SHAPE

#include "base-types.hpp"
#include "getline.hpp"
namespace averenkov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t s) = 0;
    virtual void move(double x_plus, double y_plus) = 0;
    virtual void scale(double factor) = 0;
  };
}

#endif
