#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
namespace petrov
{
  struct Triangle: petrov::Shape
  {
  public:
    Triangle(petrov::point_t p1, petrov::point_t p2, petrov::point_t p3);
    double getArea() const override;
    petrov::rectangle_t getFrameRect() const override;
    void move(petrov::point_t concrete_point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    petrov::point_t p1_, p2_, p3_;
    petrov::rectangle_t frame_rect_;
  };
}
#endif
