#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
namespace sharifullina
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t lowLeft, point_t uppRight);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t p) override;
    void move(double dx, double dy) override;
    void scaleWithoutCheck(double k) override;
  private:
    point_t lowLeft_;
    point_t uppRight_;
  };
}

#endif
