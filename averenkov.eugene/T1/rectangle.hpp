#ifndef RECTANGLE
#define RECTANGLE
#include "shape.hpp"

namespace averenkov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle();
    Rectangle(point_t a_, point_t c_);
    double getArea() const;
 void makeMOM();
    rectangle_t getFrameRect() const;
    void scale(double factor);
    void move(point_t s);
    void move(double x_plus, double y_plus);
    point_t getLeftBottom() const;
    point_t getRightTop() const;
  private:
    point_t a_, c_;
  };
}
#endif
