#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"

namespace demehin
{
  class Ring: public Shape
  {
  public:
    Ring(double cent_x, double cent_y, double out_r, double in_r);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t center_;
    double in_r_;
    double out_r_;
  };
}


#endif
