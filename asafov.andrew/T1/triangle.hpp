#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace asafov
{
  class Triangle final : public Shape
  {
  public:
    Triangle(point_t one, point_t two, point_t three);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double scale);
  private:
    point_t one_;
    point_t two_;
    point_t three_;
  };
}
#endif
