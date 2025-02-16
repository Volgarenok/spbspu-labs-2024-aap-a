#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "polygon.hpp"

namespace mozhegova
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t pCent, point_t pVert, point_t pHori);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scaleImpl(double k) override;
  private:
    Polygon poly_;
  };
}

#endif
