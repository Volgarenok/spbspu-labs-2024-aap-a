#ifndef RECTANGE_HPP
#define RECTANGE_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace nikonov
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(const point_t &lbp, const point_t &rtp);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t &a) noexcept override;
    void move(double x, double y) noexcept override;
    void scale(double k) noexcept override;
  private:
    point_t lbp_;
    point_t rtp_;
  };
}
#endif
