#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace guseynov
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(point_t leftLowP, double length);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t leftLowP_;
    point_t leftHighP_;
    point_t rightLowP_;
  };
}

#endif
