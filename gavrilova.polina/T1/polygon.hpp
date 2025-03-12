#ifndef POLYGON_HPP
#define POLYGON_HPP
#include <cstddef>
#include "shape.hpp"
#include "triangle.hpp"

namespace gavrilova {
  class Polygon final: public Shape {
  public:
    Polygon(const Polygon& other);
    Polygon(size_t size, const point_t* verteces);
    ~Polygon();

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& p) override;
    void move(double difX, double difY) override;
    Shape* clone() const override;
    void scaleWithoutCheck(double k) noexcept override;
  private:
    size_t size_;
    Shape** triangles_;
    void clear() noexcept;
  };
}
#endif
