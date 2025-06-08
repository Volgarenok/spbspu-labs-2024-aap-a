#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace komarova
{
  struct Rectangle final: public Shape
  {
  public:
    Rectangle(point_t low_left, point_t up_right);
    ~Rectangle() override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy);
    void move(point_t point) override;
    void scaleUnsafe(double coef) override;
  private:
    const size_t cnt_trg = 8;
    Shape** triangles_;

    void clear();
    void clear(size_t cnt);
    Shape** initialiseTriangles(point_t low_left, point_t up_right);
  };
}

#endif
