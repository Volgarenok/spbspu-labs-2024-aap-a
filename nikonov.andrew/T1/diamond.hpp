#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "triangle.hpp"
namespace nikonov
{
  class Diamond final: public Shape
  {
  public:
    Diamond(const point_t &p1, const point_t &p2, const point_t &p3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &a) override;
    void move(double x, double y) override;
    void scale(double k) noexcept override;
    Shape *clone() const override;
  private:
    Triangle lt_;
    Triangle lb_;
    Triangle rt_;
    Triangle rb_;
  };
}
#endif
