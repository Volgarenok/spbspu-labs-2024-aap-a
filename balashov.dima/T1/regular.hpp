#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"

namespace balashov
{
  class Regular: public Shape
  {
  public:
    Regular(point_t first_point, point_t second_point, point_t third_point);
    double getArea() const override;
    rectangle_t getFrameRect() const;
    void move(double x, double y) override;
    void move(const point_t s) override;
    void scale(double k) override;
  private:
    point_t first_point_;
    point_t second_point_;
    point_t third_point_;
  };
}

#endif
