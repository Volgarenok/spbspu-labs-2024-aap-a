#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"

namespace balashov
{
  struct Regular : public Shape
  {
  public:
    Regular(point_t center, point_t pnt2, point_t pnt3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pnt) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t point1, point2, point3;
  };
}
#endif
