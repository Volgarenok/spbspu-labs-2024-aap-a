#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace guseynov
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(guseynov::point_t leftLowP, guseynov::point_t leftHighP, guseynov::point_t rightLowP);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(guseynov::point_t pos) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    guseynov::point_t leftLowP_;
    guseynov::point_t leftHighP_;
    guseynov::point_t rightLowP_;
  };
}

#endif
