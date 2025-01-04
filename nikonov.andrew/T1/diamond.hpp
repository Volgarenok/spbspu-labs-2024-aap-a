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
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &a) override;
    void move(double x, double y) override;
    void scaleWithoutCheck(double k) override;
  private:
    point_t topP_;
    point_t midP_;
    point_t rightP_;
  };
}
#endif
