#ifndef POLYGON_HPP
#define POLYGON_HPP
#include <cstddef>
#include "shape.hpp"
#include "triangle.hpp"
namespace karnauhova
{
  class Polygon final: public Shape
  {
  public:
    Polygon(point_t* points, size_t count);
    void move(double x, double y) override;
    void move(point_t t) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void scale(double k) override;
    ~Polygon();
  private:
    Triangle** triangles_;
    size_t count_;
  };
}

#endif
