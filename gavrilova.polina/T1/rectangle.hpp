#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace gavrilova {
  class Rectangle final : public Shape {
  public:
    Rectangle(const point_t& pBottomLeft, const point_t& pTopRigh);
    Rectangle(const Rectangle& other);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t& p) noexcept override;
    void move(double difX, double difY) noexcept override;
    void scale(double k) override;
    Shape* clone() const;
  private:
    point_t pBottomLeft_;
    point_t pTopRight_;
  };
}
#endif
