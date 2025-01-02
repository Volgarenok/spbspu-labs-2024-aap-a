#ifndef KIZHIN_T1_REGULAR_HPP
#define KIZHIN_T1_REGULAR_HPP

#include <cstddef>
#include "shape.hpp"

namespace kizhin {
  class Regular final: public Shape
  {
  public:
    Regular(const point_t&, const point_t&, const point_t&);

    rectangle_t getFrameRect() const override;
    double getArea() const override;

    void move(double, double) override;
    void move(const point_t&) override;
    void scale(double) override;

  private:
    point_t vertex_;
    size_t size_;
    rectangle_t frame_;

    void computeFrameRect();
    point_t* computeVerticesArray() const;
  };
}

#endif

