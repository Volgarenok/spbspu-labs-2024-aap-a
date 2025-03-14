#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace lanovenko
{
  class Parallelogram final: public Shape
  {
  public:
    ~Parallelogram() = default;
    Parallelogram(point_t p1, point_t p2, point_t p3);
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(point_t p) override;
    virtual void move(double dx, double dy) override;
    virtual void unsafeScale(double k) override;
  private:
    point_t first_;
    point_t second_;
    point_t third_;
  };
}

#endif
