#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "polygon.hpp"

namespace demehin
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(const point_t& left_bot, const point_t& right_top);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double x, double y) override;
    void scaleUnsafely(double k) override;
  private:
    Polygon plg_;
  };
}

#endif
