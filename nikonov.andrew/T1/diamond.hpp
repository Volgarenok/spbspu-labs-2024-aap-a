#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include "triangle.hpp"
namespace nikonov
{
  class Diamond final: public Shape
  {
  public:
    Diamond(const point_t &p1, const point_t &p2, const point_t &p3);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t &a) noexcept override;
    void move(double x, double y) noexcept override;
    void scale(double k) noexcept override;
  private:
    Triangle lt_tgl_;
    Triangle lb_tgl_;
    Triangle rt_tgl_;
    Triangle rb_tgl_;
  };
}
#endif
