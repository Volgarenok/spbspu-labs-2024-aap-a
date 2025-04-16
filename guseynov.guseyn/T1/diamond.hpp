#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace guseynov
{
  class Diamond final : public Shape
  {
  public:
    Diamond(point_t highP, point_t rightP, point_t centerP);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double x, double y) override;
    void scaleWithoutCheck(double k) override;
    Shape * clone() const override;
  private:
    point_t highP_;
    point_t rightP_;
    point_t center_;
    void assigment(point_t highP, point_t rightP, point_t center);
  };
}


#endif
