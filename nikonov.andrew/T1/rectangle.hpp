#ifndef RECTANGE_HPP
#define RECTANGE_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace nikonov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t lbp, point_t rtp);
    float getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(float x, float y) override;
    void scale(float k) override;
  private:
    point_t lbp_, rtp_;
  };
}
#endif
