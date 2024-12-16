#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace kushekbaev
{
  class Diamond : public Shape
  {
  public:
    Diamond(point_t first, point_t second, point_t third);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t Z) override;
    void move(double dx, double dy) override;
    void scale(double V) override;

  private:
    point_t first_;
    point_t second_;
    point_t third_;
  };
}

#endif
