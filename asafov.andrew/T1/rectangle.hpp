#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
using asafov::point_t;
using asafov::rectangle_t;
namespace asafov
{
  class Rectangle : public Shape
  {
    point_t lb;
    point_t rt;
  public:
    Rectangle(point_t a, point_t b);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double scale);
  };
}
#endif
