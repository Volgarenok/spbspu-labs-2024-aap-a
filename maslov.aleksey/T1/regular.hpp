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
    void scale(double k) override;
   private:
    point_t A_, B_, C_;
    double AB_, AC_, BC_, rI_, rC_, halfSide_;
    size_t n_;
    double getDistance(point_t A, point_t B);
    double findRadiusIncircle(double AC, double AB, double BC);
    double findRadiusCircumcircle(double AC, double AB);
    double findHalfSide(double AC, double AB, double BC);
    bool isRegular(point_t A, point_t B, point_t C);
    size_t findVerticals(double cat1, double cat2, double hyp);
  };
}

#endif
