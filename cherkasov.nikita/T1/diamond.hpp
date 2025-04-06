#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace cherkasov
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t vertex1, point_t vertex2, point_t vertex3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t c) override;
    void move(double dx, double dy) override;
    void scalingFactor(double k) override;
  private:
    point_t vertex[4];
  };
}
#endif
