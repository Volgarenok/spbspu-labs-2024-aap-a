#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace guseynov
{
  class Diamond final : public Shape
  {
  public:
    Diamond(point_t a, point_t b, point_t c);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t new_center) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scaleWithoutCheck(double n) override;
    Shape * clone() const override;
  private:
    point_t center_;
    point_t horizontal_;
    point_t vertical_;
  };
}

#endif
