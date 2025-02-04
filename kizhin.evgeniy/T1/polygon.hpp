#ifndef KIZHIN_T1_POLYGON_HPP
#define KIZHIN_T1_POLYGON_HPP

#include <cstddef>
#include "shape.hpp"

namespace kizhin {
  class Polygon final: public Shape
  {
  public:
    Polygon(const Polygon&);
    Polygon(Polygon&&) noexcept;
    Polygon(point_t*, size_t);
    ~Polygon();

    Polygon& operator=(const Polygon&);
    Polygon& operator=(Polygon&&) noexcept;

    rectangle_t getFrameRect() const override;
    double getArea() const override;
    Shape* clone() const override;

    void move(double, double) override;
    void move(const point_t&) override;
    void unsafeScale(double) override;

  private:
    point_t* vertices_;
    size_t size_;
    point_t center_;
    rectangle_t frame_;

    void computeFrameRect();
    void computeCenter();
    void clear() noexcept;
    void swap(Polygon&) noexcept;
  };
}

#endif

