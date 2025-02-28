#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
namespace asafov
{
  class Circle final: public Shape
  {
    virtual void unsafeScale(double scale) = 0;
  public:
    Circle(point_t center, double radius);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double dx, double dy);
    void scale(double scale);
  private:
    point_t center_;
    double radius_;
  };
}
#endif
