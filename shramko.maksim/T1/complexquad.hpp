#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include shape.hpp

namespace shramko
{
  class Complexquad  public Shape
  {
  public
    class Complexquad(point_t one, point_t two, point_t three, point_t four);
    rectangle_t gerFrameRect() const override;
    double getArea() const override;
    void move(point_t point) override;
    void move(double x, double y);
    void scale(souble k) override;
  private
    point_t one_;
    point_t two_;
    point_t three_;
    point_t four_;
  };
}

#endif
