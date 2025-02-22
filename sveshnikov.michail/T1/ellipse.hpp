#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

namespace sveshnikov
{
  class Ellipse final: public Shape
  {
  public:
    Ellipse(point_t center, double vert_radius, double horiz_radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t p) override;
    void move(double dx, double dy) override;
    void unsafeScale(double k) override;
    Shape *clone() const override;

  private:
    point_t center_;
    double vert_radius_;
    double horiz_radius_;
  };
}

#endif
