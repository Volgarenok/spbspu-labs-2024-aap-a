#ifndef RECTANGE_HPP
#define RECTANGE_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace nikonov
{
  struct Rectangle: Shape
  {
    Rectangle(point_t lbp, point_t rtp);
    float getArea() const override;
    nikonov::rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(float x, float y) override;
    void scale(float k) override;
    rectangle_t frameRect;
    float width_, height_;
    point_t pos_;
  };
}
#endif
