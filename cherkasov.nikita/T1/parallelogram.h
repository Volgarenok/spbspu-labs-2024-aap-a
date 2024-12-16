#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "shape.h"
namespace cherkasov
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(point_t point1, point_t point2, point_t point3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t c) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t point1;
    point_t point2;
    point_t point3;
    point_t center;
    double length;
    double height;
    void calculateCenter();
  };
}
#endif
