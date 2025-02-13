#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"
namespace asafov
{
  class Ellipse : public Shape
  {
    point_t center;
    double verticalradius;
    double horizontalradius;
  public:
    Ellipse(point_t pos, double radv, double radh);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double scale);
  };
}
#endif
