#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace nikonov
{
  class Triangle final: public Shape
  {
  public:
    Triangle(const point_t &a, const point_t &b, const point_t &c);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t &a) noexcept override;
    void move(double x, double y) noexcept override;
    void scale(double k) noexcept override;
  private:
    point_t a_;
    point_t b_;
    point_t c_;
  };
}
#endif
