#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <cstddef>
#include "shape.hpp"

namespace duhanina
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(const point_t& lt, const point_t& rt);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newPos) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Shape** fillWithEllipses(const point_t& lt, const point_t& rt);

  private:
    size_t cuts_;
    Shape** ellipses_;
    double ellWidth_;
    double ellHeight_;
  };
}

#endif
