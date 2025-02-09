#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "shape.hpp"

namespace maslevtsov
{
  struct Polygon final: public Shape
  {
  public:
    Polygon(const Polygon& rhs);
    Polygon(std::size_t nVertices, const point_t* vertices);
    ~Polygon() override;
    Polygon& operator=(const Polygon& rhs);

    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t pnt) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double k) override;
    void unsafeScale(double k) noexcept override;

  private:
    std::size_t nVertices_;
    point_t* vertices_;
  };

  Polygon* makePolygon(const double* arguments, std::size_t nArguments);
}

#endif
