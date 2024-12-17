#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"

namespace smirnov
{
  class Diamond : public Shape
  {
  private:
    point_t center;
    double diagonal1;
    double diagonal2;
  public:
    Diamond(double x1, double y1, double x2, double y2, double x3, double y3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  };
}
#endif
