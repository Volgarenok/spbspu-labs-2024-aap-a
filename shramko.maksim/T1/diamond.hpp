#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace shramko
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t one, point_t two, point_t three);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double x, double y) override;
  private:
    point_t vertices_[4];
    point_t center_;
    void doScale(double k) override;
  };
}

#endif
