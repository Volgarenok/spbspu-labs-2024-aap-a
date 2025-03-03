#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace ivanova
{
  class Diamond : public Shape
  {
  public:
    Diamond(point_t topPoint, point_t bottomPoint, point_t center);

    double getArea() const override;
    rectangle_t getFrameRect() const override;

    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double ratio) override;

  private:
    point_t topPoint_;
    point_t bottomPoint_;
    point_t center_;
  };
}

#endif
