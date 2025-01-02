#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace savintsev
{
  class Rectangle final : public Shape
  {
  public:
    Rectangle(point_t lhs, point_t rhs);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double x, double y) override;
  private:
    void doScale(double k) override;
    point_t pLowLeft_;
    point_t pUpRight_;
  };
}
#endif
