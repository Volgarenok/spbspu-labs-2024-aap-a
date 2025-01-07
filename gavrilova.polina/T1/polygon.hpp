#ifndef POLYGON_HPP
#define POLYGON_HPP
#include <cstddef>
#include "shape.hpp"
#include "triangle.hpp"

namespace gavrilova {
  class Polygon final : public Shape {
  public:
    ~Polygon();
    Polygon(size_t size, point_t* verteces);
    Polygon(const Polygon& other);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(const point_t& p) noexcept override;
    void move(double difX, double difY) noexcept override;
    Shape* clone() const;
    void scale_without_check(double k) override;
  private:
    size_t size_;
    Triangle** triangles_;
    void clear(size_t created);
  };
}
#endif

