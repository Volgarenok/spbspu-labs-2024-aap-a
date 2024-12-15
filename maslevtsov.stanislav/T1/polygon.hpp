#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "shape.hpp"

namespace maslevtsov
{
  struct Polygon: public Shape
  {
  public:
    ~Polygon() override;
    Polygon(std::size_t nVertices, point_t* vertices);
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t pnt) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double k) noexcept override;

  private:
    std::size_t nVertices_;
    point_t* vertices_;
  };

  Polygon* makePolygon(const double* arguments);
}

#endif
