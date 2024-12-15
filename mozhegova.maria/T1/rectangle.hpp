#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace mozhegova
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t lowLef, point_t uppRig);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t lowerLeft = {0.0, 0.0};
    point_t upperRight = {0.0, 0.0};
  };
}

#endif
