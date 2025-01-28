#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

namespace duhanina
{
  class Ellipse final: public Shape
  {
  public:
    Ellipse(const point_t& center, double vertRadius, double horizRadius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
    void scaleUnsafe(double k) noexcept override;

  private:
    point_t center_;
    double vertRadius_;
    double horizRadius_;
  };
}

#endif
