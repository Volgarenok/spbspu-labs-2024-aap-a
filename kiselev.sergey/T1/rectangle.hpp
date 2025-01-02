#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace kiselev
{
  class Rectangle final : public Shape
  {
  public:
    Rectangle(point_t leftDown, point_t rightUp);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t a) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double k) override;

  private:
    point_t leftDown_;
    point_t rightUp_;
  };
}
#endif
