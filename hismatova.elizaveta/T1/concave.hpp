#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"

namespace hismatova
{
  class Concave final: public Shape
  {
  public:
    Concave(const point_t& a, const point_t& b, const point_t& c, const point_t& d);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t& newPos) override;
    void scale(double index) override;
  private:
    point_t a_, b_, c_, d_;
    void movePoint(point_t& point, double dx, double dy);
    void scalePoint(point_t& point, const point_t& center, double index);
  };
}

#endif
