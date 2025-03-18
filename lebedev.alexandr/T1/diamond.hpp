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
    ~Diamond();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    Concave** concaves_;
    size_t concaveCount_;
    size_t capacity_;
    void expandArray();
    point_t getMiddlePoint(point_t p1, point_t p2) const;
    void divideIntoConcaves(point_t centre, point_t vert, point_t horiz);
    double getCurrentDiamondArea(point_t centre, point_t vert, point_t horiz) const;
  };
}
#endif
