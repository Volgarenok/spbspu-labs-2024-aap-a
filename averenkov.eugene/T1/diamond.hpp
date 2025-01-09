#ifndef DIAMOND
#define DIAMOND

#include "shape.hpp"
#include "rectangle.hpp"

namespace averenkov
{
  class Diamond : public Shape
  {
  public:
    Diamond(point_t a_, point_t b_, point_t c_);
    void buildRectangles(const point_t a, const point_t b, const point_t c);
    void scale(double factor);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t s);
    void move(double x_plus, double y_plus);
  private:
    Rectangle rectangles[40];
    double widthR, heightR;
  };
}

#endif
