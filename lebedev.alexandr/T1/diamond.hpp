#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
#include "concave.hpp"

namespace lebedev
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t centre, point_t vert, point_t horiz);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t centre_;
    point_t vert_;
    point_t horiz_;
  };
}
#endif
