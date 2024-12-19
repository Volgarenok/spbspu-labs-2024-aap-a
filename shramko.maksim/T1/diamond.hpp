#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace shramko
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t one, point_t two, point_t three);
    double getArea() const override;
    rectangle_t getRectangleFrame() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t one_;
    point_t two_;
    point_t three_;
  };
}

#endif
