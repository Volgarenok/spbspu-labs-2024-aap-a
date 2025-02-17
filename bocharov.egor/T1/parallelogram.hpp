#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"
namespace bocharov
{
  class Parallelogram final: public Shape
  {
  public:
    Parallelogram(point_t p1, point_t p2, point_t p3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double ratio) override;
  private:
    point_t pos_;
    point_t p1_;
    point_t p2_;
  };
}
#endif
