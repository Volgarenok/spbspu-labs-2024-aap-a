#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "tools.hpp"

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
    point_t center_;
    point_t top_;
    point_t left_;

    point_t findCenter(point_t a, point_t b, point_t c);
    point_t findTop(point_t a, point_t b, point_t c);
    point_t findLeft(point_t a, point_t b, point_t c);
    bool isCenter(point_t check, point_t a, point_t b);
  };
}

#endif
