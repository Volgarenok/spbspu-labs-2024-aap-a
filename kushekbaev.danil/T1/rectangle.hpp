#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace kushekbaev
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(point_t lowerLeft, point_t upperRight);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t scalePoint) override;
    void move(double dx, double dy) override;
    Shape* clone() const override;
    virtual void doUnsafeScale(double scaleCoeff) override;

  private:
    point_t lowerLeft_;
    point_t upperRight_;
  };
}

#endif
