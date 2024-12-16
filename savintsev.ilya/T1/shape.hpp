#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <cstddef>
#include <iostream>
#include "base-types.hpp"

namespace savintsev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t p) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double k) = 0;
  };

  void scaleRelativeTo(Shape * rhs, point_t p, double k);
  void scaleAllRelativeTo(Shape ** rhs, size_t amt, point_t p, double k);
  void printSumAreaAndBorders(std::ostream & out, Shape ** rhs, size_t amt);
  int actWithShpByDesc(char * desc, Shape ** rhs, size_t & amt, point_t & p, double & k);
  void destroyArray(Shape ** rhs, size_t amt);

}
#endif
