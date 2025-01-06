#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"
namespace gavrilova {
  class Ellipse final : public Shape {
  public:
    Ellipse(const point_t& center, double radiusX, double radiusY);
    Ellipse(const Ellipse& other);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t& p) noexcept override;
    void move(double difX, double difY) noexcept override;
    Shape* clone() const;
    void scale(double k) override;

  private:
    point_t center_;
    double radiusY_;
    double radiusX_;
  };
}
#endif

