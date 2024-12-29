#ifndef POLYGON_HPP
#define POLYGON_HPP
#include <cstddef>
#include "shape.hpp"
namespace gavrilova {
  class Polygon : public Shape {
  public:
    ~Polygon();
    Polygon(size_t size, point_t * verteces);
    Polygon(const Polygon& other);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double difX, double difY) override;
    void scale(double k) override;
    Shape* clone() const;
    point_t getCenter();
  private:
    size_t size_;
    point_t * verteces_;
  };
}
#endif
