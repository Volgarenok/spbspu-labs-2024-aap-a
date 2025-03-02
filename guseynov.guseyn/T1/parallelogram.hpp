#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace guseynov
{
  class Parallelogram final : public Shape
  {
  public:
    Parallelogram(point_t leftLowP, point_t leftHighP, point_t rightLowP);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(guseynov::point_t pos) override;
    void move(double x, double y) override;
    void scaleWithoutCheck(double k) override;
    Shape * clone() const override;
  private:
    point_t pos_;
    point_t p1_;
    point_t p2_;
    point_t pt1_;
    point_t pt2_;
    point_t pt3_;
  };
}

#endif
