#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "triangle.hpp"
namespace bocharov
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(point_t leftDown, point_t rightUp);
    double getArea() const  override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double ratio) override;
  private:
    Triangle ta_{{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}};
    Triangle tb_{{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}};
    Triangle tc_{{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}};
    Triangle td_{{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}};
  };
}
#endif
