#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace kushekbaev
{
  struct Rectangle : public Shape
  {
    Rectangle(point_t lowerLeft, point_t upperRight);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t Z) override;
    void move(double dx, double dy) override;
    void scale(double V) override;

    private:
      point_t lowerLeft_;
      point_t upperRight_;
  };
}

#endif
