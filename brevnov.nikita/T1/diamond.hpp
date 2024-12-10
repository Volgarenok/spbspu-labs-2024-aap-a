#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
namespace brevnov
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t center, point_t horizontal, point_t vertical);
    double getArea();
    rectangle getFrameRect();
    void move(point_t new_centre);
    void move(double dx, double dy);
    void scale(double n);
  private:
    point_t center;
    point_t horizantal;
    point_t vertical;
  };
}
#endif
