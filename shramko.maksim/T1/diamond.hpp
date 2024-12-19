#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace shramko
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t One, point_t Two, point_t Three);
    double getArea() const override;
    rectangle_t getRecctangleFrame() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    point_t One_;
    point_t Two_;
    point_t Three_;
  };
}

#endif
