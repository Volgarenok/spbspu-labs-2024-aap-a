#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace gavrilova {
  class Triangle final : public Shape {
  public:
    Triangle(const point_t& a, const point_t& b, const point_t& c);
    Triangle(const Triangle& other);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t& p) noexcept override;
    void move(double difX, double difY) noexcept override;
    void scale(double k) override;
    Shape* clone() const;
    
  private:
    point_t a_;
    point_t b_;
    point_t c_;
  };
}
#endif
