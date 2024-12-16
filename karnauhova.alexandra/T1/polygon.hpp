#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "shape.hpp"
#include <cstddef>
namespace karnauhova
{
  class Polygon: public Shape
  {
  public:
    Polygon(point_t* points, size_t count): points_(points), count_(count)
    {}
    void move(double x, double y) override;
    void move(point_t t) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void scale(point_t t, double k) override;
    ~Polygon() {}
  private:
    point_t* points_;
    size_t count_;
  };
}

#endif
