#ifndef RECTANGLE
#define RECTANGLE
#include "shape.hpp"

namespace averenkov
{
  class Rectangle : public Shape
  {
  private:
    point_t a, c;
  public:
    void scale(point_t s, double factor);
    Rectangle(point_t a_, point_t c_);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t s);
    void move(double x_plus, double y_plus);
  };
}
#endif
