#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace guseynov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t leftLowP, point_t rightHighP);
    double getArea();
    rectangle_t getFrameRect();
    void move(point_t pos);
    void move(double x, double y);
    void scale(double k);
  private:
    point_t leftLowP_;
    point_t rightHighP_;
  };
}

#endif
