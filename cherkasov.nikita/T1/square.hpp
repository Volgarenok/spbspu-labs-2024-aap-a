#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace cherkasov
{
  class Square final: public Shape
  {
  public:
    Square(point_t left, double length);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t c) override;
    void move(double dx, double dy) override;
    void scalingFactor(double k) override;
  private:
    point_t left;
    double length;
  };
}
#endif
