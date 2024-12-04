#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace kiselev
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t leftDown, point_t rightUp);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t a);
    void move(double dx, double dy);
    void scale(double k);

  private:
    point_t leftDown_;
    point_t rightUp_;
  };
}
#endif

