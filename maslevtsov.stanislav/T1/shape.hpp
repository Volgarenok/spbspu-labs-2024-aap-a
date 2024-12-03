#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <istream>
#include "base-types.hpp"

namespace maslevtsov
{
  struct Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t pnt) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
  };

  Shape* makeShape(std::istream& in);
  void scale(Shape* shape, point_t pnt, double k);
}

#endif
