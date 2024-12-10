#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace brevnov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t left, point_t right);
    double getArea();
    rectangle_t getFrameRect();
    void move(point_t new_centre);
    void move(double dx, double dy);
    void scale(double n);
  private:
    point_t left;
    point_t right;
  };
}
#endif