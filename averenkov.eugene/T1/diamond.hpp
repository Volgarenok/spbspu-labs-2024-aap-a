#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
#include "rectangle.hpp"

namespace averenkov
{
  class Diamond final: public Shape
  {
  public:
    Diamond(const point_t& a, const point_t& b, const point_t& c);
    ~Diamond();
    void scaleNonChecked(double factor) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& s) override;
    void move(double dx, double dy) override;
  private:
    Rectangle** rectangles_;
  };
}

#endif
