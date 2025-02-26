#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace dirti
{
  struct Rectangle final: public Shape
  {
  public:
    Rectangle(const point_t left_low, const point_t right_high);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void unsafeScale(double koef) override;
  private:
    point_t left_low_;
    point_t right_high_;
  };
}
#endif