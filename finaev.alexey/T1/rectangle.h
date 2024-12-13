#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "base-types.h"

namespace finaev
{
  class Rectangle :public Shape
  {
  private:
    point_t leftDown;
    point_t rightUp;
  public:
    Rectangle(point_t l, point_t r);
    double getArea() override;
    point_t getCentre();
    rectangle_t getFrameRect() override;
    void move(point_t a) override;
    void move(double sx, double sy) override;
    void scale(size_t k) override;
  };
}
#endif
