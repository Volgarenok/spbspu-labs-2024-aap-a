#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
#include "complexquad.hpp"
namespace kiselev
{
  class Diamond final : public Shape
  {
  public:
    Diamond(point_t pVertical, point_t pHorizontal);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t a) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double k) noexcept override;

  private:
    Complexquad * comp1;
    Complexquad * comp2;
  };
}
#endif
