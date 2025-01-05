#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace gavrilova {
  class Rectangle final : public Shape {
  public:
    Rectangle(point_t pBottomLeft, point_t pTopRigh);
    Rectangle(const Rectangle& other);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double difX, double difY) override;
    void scale(double k) override;
    Shape* clone() const;
  private:
    point_t pBottomLeft_;
    point_t pTopRight_;
  };
}
#endif
