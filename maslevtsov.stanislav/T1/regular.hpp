#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"
#include "polygon.hpp"

namespace maslevtsov
{
  struct Regular final: public Shape
  {
  public:
    Regular(point_t center, point_t pnt2, point_t pnt3);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t pnt) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double k) override;
    void unsafeScale(double k) noexcept override;

  private:
    Polygon polygon_;
  };
}

#endif
