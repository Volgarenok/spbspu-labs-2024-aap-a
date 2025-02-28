#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"
namespace asafov
{
  class Ellipse final: public Shape
  {
  public:
    Ellipse(point_t center, double verticalradius, double horizontalradius);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double dx, double dy);
    void unsafeScale(double scale);
  private:
    point_t center_;
    double verticalradius_;
    double horizontalradius_;
  };
}
#endif
