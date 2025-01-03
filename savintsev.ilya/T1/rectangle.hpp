#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "complexquad.hpp"

namespace savintsev
{
  class Rectangle final : public Shape
  {
  public:
    Rectangle(point_t lhs, point_t rhs);
    ~Rectangle() override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double x, double y) override;
    Shape * clone() const override;
  private:
    void doScale(double k) override;
    Complexquad * stay_;
    Complexquad * lay_;
  };
}
#endif
