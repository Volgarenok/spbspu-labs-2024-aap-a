#ifndef REGULAR_HPP
#define REGULAR_HPP

#include <cstddef>
#include "shape.hpp"

namespace maslov
{
  struct Regular final: public Shape
  {
    Regular(point_t a, point_t b, point_t c);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double dx, double dy) override;
    void scaleWithoutCheck(double k) override;
    Shape * clone() const override;
   private:
    point_t a_;
    point_t b_;
    point_t c_;
    size_t n_;
    double getDistance(point_t a, point_t b) const;
    double getRadiusIncircle() const;
    double getRadiusCircumcircle() const;
    double getHalfSide() const;
    bool isRegular() const;
    size_t getVerticals() const;
  };
}

#endif
