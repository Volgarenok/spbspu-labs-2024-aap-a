#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace gavrilova {
  class Rectangle final: public Shape {
  public:
    Rectangle(const point_t& pBottomLeft, const point_t& pTopRigh);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& p) override;
    void move(double difX, double difY) override;
    Shape* clone() const;
    void scaleWithoutCheck(double k) noexcept override;
  private:
    point_t pBottomLeft_;
    point_t pTopRight_;
  };
}
#endif
