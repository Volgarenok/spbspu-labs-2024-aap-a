#ifndef REGULAR_HPP
#define REGULAR_HPP

#include <cstddef>
#include "shape.hpp"

namespace maslov
{
  struct Regular final: public Shape
  {
    Regular(point_t A, point_t B, point_t C);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double dx, double dy) override;
    void scaleWithoutCheck(double k) override;
    Shape * clone() const override;
   private:
    point_t A_;
    point_t B_;
    point_t C_;
    size_t n_;
    double getDistance(point_t A, point_t B) const;
    double getRadiusIncircle() const;
    double getRadiusCircumcircle() const;
    double getHalfSide() const;
    bool isRegular() const;
    size_t getVerticals() const;
  };
}

#endif
