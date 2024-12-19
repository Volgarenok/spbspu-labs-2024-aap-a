#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"

namespace maslevtsov
{
  struct Regular: public Shape
  {
  public:
    Regular(point_t center, point_t pnt2, point_t pnt3);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t pnt) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double k) noexcept override;

  private:
    point_t center_, pnt2_, pnt3_;
  };

  Regular* makeRegular(const double* arguments);
}

#endif
