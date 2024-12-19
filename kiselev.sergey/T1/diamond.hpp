#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
namespace kiselev
{
  class Diamond : public Shape
  {
  public:
    Diamond(point_t center, point_t pVertical, point_t pHorizontal);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t a);
    void move(double dx, double dy);
    void scale(double k);

  private:
    point_t center_;
    point_t pVertical_;
    point_t pHorizontal_;
  };
}
#endif

