#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"
namespace brevnov
{
  class Ellipse : public Shape
  {
  public:
    Ellipse(point_t center, double r1, double r2);
    ~Ellipse();
    double getArea();
    rectangle_t getFrameRect();
    void move(point_t new_centre);
    void move(double dx, double dy);
    void scale(double n);
  private:
    point_t center;
    double r1;
    double r2;
  };
}
#endif
