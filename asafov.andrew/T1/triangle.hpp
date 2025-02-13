#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace asafov
{
  class Triangle : public Shape
  {
    point_t one;
    point_t two;
    point_t three;
  public:
    Triangle(point_t a, point_t b, point_t c);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double scale);
  };
}
#endif
