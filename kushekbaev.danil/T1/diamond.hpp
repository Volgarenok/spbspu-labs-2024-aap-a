#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace kushekbaev
{
  class Diamond : public Shape
  {
  public:
    Diamond(point_t middle, point_t diffX, point_t diffY);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t Z) override;
    void move(double dx, double dy) override;
    void scale(double V) override;

  private:
    point_t middle_;
    point_t diffX_;
    point_t diffY_;
  };
}

#endif
