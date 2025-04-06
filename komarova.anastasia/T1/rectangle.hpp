#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
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
    void scale(double coef) override;
  private:
    Shape** triangles_;

    void clear();
  };
}

#endif
