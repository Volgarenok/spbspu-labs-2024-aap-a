#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "shape.h"
#include "base-types.h"

namespace cherkasov
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t c);
    void move(double dx, double dy);
    void scale(double k);
  private:
    point_t vertex1_;
    point_t vertex2_;
    point_t vertex3_;
    point_t vertex4_;
    point_t center_;
  };
}
#endif
