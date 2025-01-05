#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"
namespace brevnov
{
  class Ellipse final: public Shape
  {
  public:
    Ellipse(point_t center, double r1, double r2);
    ~Ellipse() = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t new_centre) override;
    void move(double dx, double dy) override;
    void scale(double n) override;
  private:
    point_t center_;
    double r1_;
    double r2_;
  };
}
#endif
