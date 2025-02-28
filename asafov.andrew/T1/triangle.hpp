#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace asafov
{
  class Triangle final: public Shape
  {
  public:
    Triangle(point_t one, point_t two, point_t three);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double dx, double dy);
    void unsafeScale(double k);
  private:
    point_t points_[3];
  };
}
#endif
