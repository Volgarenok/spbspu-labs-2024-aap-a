#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace asafov
{
  class Rectangle final : public Shape
  {
  public:
    Rectangle(point_t a, point_t b);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double scale);
  private:
    point_t lb_;
    point_t rt_;
  };
}
#endif
