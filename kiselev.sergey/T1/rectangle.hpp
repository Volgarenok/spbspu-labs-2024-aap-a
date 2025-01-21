#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace kiselev
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(point_t leftDown, point_t rightUp);
    double getArea() const override;
    Shape* clone() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t leftDown_;
    point_t rightUp_;
  };
}
#endif
