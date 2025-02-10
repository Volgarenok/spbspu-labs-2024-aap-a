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
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t new_centre) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double n) noexcept override;
    Shape * clone() const;
  private:
    point_t center_;
    double r1_;
    double r2_;
  };
}
#endif
