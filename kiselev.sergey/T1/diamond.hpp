#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "complexquad.hpp"
namespace kiselev
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t center, point_t pVertical, point_t pHorizontal);
    double getArea() const override;
    Shape* clone() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t a) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    Complexquad comp1_;
    Complexquad comp2_;
  };
}
#endif
