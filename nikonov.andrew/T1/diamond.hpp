#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace nikonov
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t topP, point_t bottomP, point_t leftP);
    double  getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(double  x, double  y) override;
    void scale(double  k) override;
  private:
    point_t topP_, rightP_, midP_;
  };
}
#endif
