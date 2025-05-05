#ifndef TRANGLE_HPP
#define TRANGLE_HPP

#include "shape.hpp"

namespace shramko
{
  class Triangle final: public Shape
  {
  friend class Diamond;
  public:
    ~Triangle() override = default;
    Triangle() = default;
    Triangle(point_t one, point_t two, point_t three);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double x, double y) override;
    void doScale(double k) override;
  private:
    point_t one_;
    point_t two_;
    point_t three_;
  };
}

#endif
