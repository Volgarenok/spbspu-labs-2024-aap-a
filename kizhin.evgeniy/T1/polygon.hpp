#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <cstddef>
#include "shape.hpp"

namespace kizhin {
  class Polygon;
}

class kizhin::Polygon : public Shape
{
public:
  Polygon(const Polygon&);
  Polygon(Polygon&&) noexcept;
  Polygon(const point_t*, size_t);
  ~Polygon();

  Polygon& operator=(const Polygon&);
  Polygon& operator=(Polygon&&) noexcept;

  rectangle_t getFrameRect() const override;
  double getArea() const override;

  void move(double, double) override;
  void move(const point_t&) override;
  void scale(double) override;
  void swap(Polygon&) noexcept;

private:
  point_t* vertices_;
  size_t size_;
  point_t center_;
  rectangle_t frame_;

  void computeFrameRect();
  void computeCenter();
};

#endif

