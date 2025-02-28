#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"
namespace asafov
{
  class Complexquad final: public Shape
  {
    void unsafeScale(double scale);
  public:
    Complexquad(point_t one, point_t two, point_t three, point_t four);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double dx, double dy);
    void scale(double scale);
  private:
    point_t points_[4];
  };
}
#endif
