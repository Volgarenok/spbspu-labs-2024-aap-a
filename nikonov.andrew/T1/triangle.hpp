#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace nikonov
{
  class Triangle: public Shape
  {
  public:
    Triangle(point_t leftP, point_t topP, point_t rightP);
    float getArea() const override;
    point_t getCenterOfGravity() const;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(float x, float y) override;
    void scale(float k) override;
  private:
    point_t A_, B_, C_;
  };
}
#endif
