#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

namespace duhanina
{
  class Ellipse final: public Shape
  {
  public:
    Ellipse(point_t center, double horizRadius, double vertRadius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t center_;
    double horizRadius_;
    double vertRadius_;
  };
}

#endif
