#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "triangle.hpp"

namespace shramko
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t one, point_t two, point_t three);
    ~Diamond();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double k) override;
  private:
    Triangle* triangles;
    point_t one_;
    point_t two_;
    point_t three_;
  };
}

#endif
