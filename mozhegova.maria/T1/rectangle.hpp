#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "polygon.hpp"

namespace mozhegova
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(point_t lowLef, point_t uppRig);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scaleImpl(double k) override;
  private:
    Polygon poly_;
  };
}

#endif
