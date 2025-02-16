#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"
namespace asafov
{
  class Ellipse final : public Shape
  {
  public:
    Ellipse(point_t pos, double radv, double radh);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double scale);
  private:
    point_t center_;
    double verticalradius_;
    double horizontalradius_;
  };
}
#endif
