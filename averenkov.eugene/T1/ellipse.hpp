#ifndef ELLIPSE
#define ELLIPSE

#include "shape.hpp"

namespace averenkov
{
  class Ellipse : public Shape
  {
  public:
    Ellipse(point_t center_, double radius_v_, double radius_h_);
    void scale(double factor);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t s);
    void move(double x_plus, double y_plus);
  private:
    point_t center;
    double radius_v;
    double radius_h;
  };
}
#endif
