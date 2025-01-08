#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"
#include "polygon.hpp"

namespace demehin
{
  class Ring final: public Shape
  {
  public:
    Ring(point_t center, double out_r, double in_r);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    Polygon inner_plg_;
    Polygon outer_plg_;
  };
}


#endif
