#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace maslov
{
  struct Rectangle : public Shape
  {
    Rectangle(point_t lowerLeftCorner, point_t upperRightCorner):
    lowerLeftCorner_(lowerLeftCorner), upperRightCorner_(upperRightCorner) {};
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
   private:
    point_t lowerLeftCorner_ = {0, 0};
    point_t upperRightCorner_ = {0, 0};
  };
}

#endif
