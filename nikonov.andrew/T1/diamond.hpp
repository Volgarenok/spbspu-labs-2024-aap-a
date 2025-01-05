#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace nikonov
{
  class Diamond final: public Shape
  {
  public:
    Diamond(const point_t &topP, const point_t &midP, const point_t &rightP);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t &a) noexcept override;
    void move(double x, double y) noexcept override;
    void scale(double k) noexcept override;
  private:
    point_t topP_;
    point_t midP_;
    point_t rightP_;
  };
}
#endif
