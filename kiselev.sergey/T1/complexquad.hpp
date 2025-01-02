#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"
namespace kiselev
{
  class Complexquad final : public Shape
  {
  public:
    Complexquad(point_t p1, point_t p2, point_t p3, point_t p4) noexcept;
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t a) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double k) noexcept override;

  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
    point_t p4_;
  };
}
#endif
