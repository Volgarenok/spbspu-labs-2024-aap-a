#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
namespace asafov
{
  class Circle final: public Shape
  {
  public:
    Circle(point_t center, double radius);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double dx, double dy);
    void unsafeScale(double );
  private:
    point_t center_;
    double radius_;
  };
}
#endif
