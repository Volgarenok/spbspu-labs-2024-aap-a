#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace nikonov
{
  class Triangle final: public Shape
  {
  public:
    Triangle(const point_t &leftP, const point_t &topP, const point_t &rightP);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &a) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t A_, B_, C_;
  };
}
#endif
