#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "base-types.hpp"
#include "shape.h"

namespace cherkasov
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3);
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
  };
}
#endif
