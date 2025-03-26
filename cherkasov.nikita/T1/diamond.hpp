#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace cherkasov
{
  class Diamond final : public Shape
  {
  public:
    Diamond(double x1, double y1, double x2, double y2, double x3, double y3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t c) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t vertex1;
    point_t vertex2;
    point_t vertex3;
    point_t vertex4;
    point_t center;
    bool areDiagonalsPerpendicular(const point_t &p1, const point_t &p3, const point_t &p2, const point_t &p4) const;
  };
}
#endif
