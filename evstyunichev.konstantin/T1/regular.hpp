#ifndef REGULAR_HPP
#define REGULAR_HPP
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
namespace evstyunichev
{
  struct Regular: public Shape
  {
    Regular(point_t, size_t, double, double);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double, double);
    void move(point_t);
    void scale(double k);
    private:
      point_t O_;
      size_t n_;
      double a_, R_, r_, base_;
  };
  double findDist(point_t, point_t);
}
#endif
