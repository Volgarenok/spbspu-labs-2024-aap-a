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
    double getArea() override;
    rectangle_t getFrameRect() override;
    void move(point_t new_centre) override;
    void move(double dx, double dy) override;
    void scale(double n) override;
  private:
    point_t center;
    double r1;
    double r2;
  };
}
#endif
