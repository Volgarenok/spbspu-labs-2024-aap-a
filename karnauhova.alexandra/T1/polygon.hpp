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
    Polygon(const point_t* points, size_t count);
    ~Polygon();
    void move(double x, double y) override;
    void move(const point_t& t) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void scale(double k) override;
    Shape* clone() const;
    void clear() noexcept;
  private:
    Shape** triangles_;
    size_t count_;
  };
}

#endif
