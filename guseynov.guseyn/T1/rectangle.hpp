#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace guseynov
{
  class Rectangle final : public Shape
  {
  public:
    Rectangle(point_t leftLowP, point_t rightHighP);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double x, double y) override;
    void scaleWithoutCheck(double k) override;
    Shape * clone() const override;
  private:
    point_t leftLowP_;
    point_t rightHighP_;
    void assigment(point_t leftLowP, point_t rightHighP);
  };
}

#endif
