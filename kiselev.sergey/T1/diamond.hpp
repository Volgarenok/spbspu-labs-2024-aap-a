#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include "complexquad.hpp"
namespace kiselev
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t center, point_t pVertical, point_t pHorizontal);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    Complexquad comp1;
    Complexquad comp2;
  };
}
#endif
