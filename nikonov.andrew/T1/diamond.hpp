#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace nikonov
{
  struct Diamond: Shape
  {
    Diamond(point_t topP, point_t bottomP, point_t leftP);
    float getArea() const override;
    nikonov::rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(float x, float y) override;
    void scale(float k) override;
    point_t topP_, rightP_, midP_;
  };
}
#endif
