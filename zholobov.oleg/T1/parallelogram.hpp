#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include <istream>

#include "shape.hpp"

namespace zholobov {

  class Parallelogram: public Shape {
  public:
    Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale_no_check(double k) override;
    Shape* clone() const override;

    static Parallelogram* create(std::istream& in);

  private:
    point_t pos_;
    point_t p1_;
    point_t p2_;
  };

}

#endif
