#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"
#include <cstddef>

namespace maslov
{
  double distance(point_t A, point_t B);
  double findRadiusIncircle(double AC, double AB, double BC);
  double findRadiusCircumcircle(double AC, double AB);
  double findHalfSide(double AC, double AB, double BC);
  bool isRegular(point_t A, point_t B, point_t C);
  
  struct Regular : public Shape
  {
    Regular(point_t A, point_t B, point_t C);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    size_t getVerticals() const;
   private:
    point_t A_ = {0, 0}, B_ = {0, 0}, C_ = {0, 0};
    double AB_ = 0.0, AC_ = 0.0, BC_ = 0.0;
    double rI_ = 0.0, rC_ = 0.0, halfSide_ = 0.0;
    size_t n_ = 0;
  };
}

#endif