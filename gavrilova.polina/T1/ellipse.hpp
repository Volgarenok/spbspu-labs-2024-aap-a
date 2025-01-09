#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"
namespace gavrilova {
  class Ellipse final: public Shape {
  public:
    Ellipse(const point_t& center, double radiusX, double radiusY);
    Ellipse(const Ellipse& other);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& p) override;
    void move(double difX, double difY) override;
    Shape* clone() const;
    void scale_without_check(double k) noexcept override;

  private:
    point_t center_;
    double radiusY_;
    double radiusX_;
  };
}
#endif

