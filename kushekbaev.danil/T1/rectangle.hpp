#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace kushekbaev
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t lowerLeft, const point_t upperRight);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t Z) override;
    void move(const double dx, const double dy) override;
    void scale(const double V) override;

  private:
    point_t lowerLeft_;
    point_t upperRight_;
  };
}

#endif
