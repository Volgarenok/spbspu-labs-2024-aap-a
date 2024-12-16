#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace hismatova
{
  class rectangle : public shape
  {
  public:
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t& newPos) override;
    void scale(double index) override;
    rectangle(const point_t& bottomLeft, const point_t& topRight);
  private:
    point_t bottomLeft_;
    point_t topRight_;
  };
}

#endif
