#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace maslov
{
  struct Parallelogram final: public Shape
  {
    Parallelogram(point_t first, point_t second, point_t third);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    Shape * clone() const;
   private:
    point_t first_, second_, third_, fourth_;
  };
}

#endif
