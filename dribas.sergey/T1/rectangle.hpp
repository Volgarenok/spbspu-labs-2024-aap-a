#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace dribas
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(point_t leftDown, point_t rightUp);
    double getArea() const override;
    Shape* clone() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double ratio) override;
  private:
    point_t leftDown_;
    point_t rightUp_;
  };
}
#endif
