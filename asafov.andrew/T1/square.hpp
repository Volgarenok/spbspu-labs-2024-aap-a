#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"
using asafov::point_t;
using asafov::rectangle_t;
namespace asafov
{
  class Square : public Shape
  {
    point_t lb;
    double side;
  public:
    Square(point_t a, double side);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(point_t pos, double scale);
  };
}
#endif
