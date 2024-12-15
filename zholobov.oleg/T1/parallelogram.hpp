#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace zholobov {

  class Parallelogram : public Shape {
    point_t pos_;
    point_t p1_;
    point_t p2_;

   public:
    Parallelogram();
    Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3);

    float getArea() override;
    rectangle_t getFrameRect() override;
    void move(point_t p) override;
    void move(float dx, float dy) override;
    void scale(float k) override;
  };

}

#endif
