#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
namespace kiselev
{
  class Diamond final : public Shape
  {
  public:
    Diamond(point_t center, point_t pVertical, point_t pHorizontal) noexcept;
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t a) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double k) noexcept override;

  private:
    point_t center_;
    point_t pVertical_;
    point_t pHorizontal_;
  };
}
#endif
