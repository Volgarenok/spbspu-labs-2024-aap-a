#ifndef DIAMOND
#define DIAMOND

#include "shape.hpp"

namespace averenkov
{
  class Diamond : public Shape
  {
  private:
    point_t a;
    point_t b;
    point_t c;
  public:
    Diamond(point_t a_, point_t b_, point_t c_);
    void scale(point_t s, double factor);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t s);
    void move(double x_plus, double y_plus);
  };
}

#endif
