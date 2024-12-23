#ifndef DIAMOND_H
#define DIAMOND_H
#include "shape.h"
#include "base-types.h"

namespace cherkasov
{
  class Diamond : public Shape
  {
  public:
    Diamond(double x1, double y1, double x2, double y2, double x3, double y3);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t c);
    void move(double dx, double dy);
    void scale(double k);
  private:
    point_t vertex1;
    point_t vertex2;
    point_t vertex3;
    point_t vertex4;
    point_t center;
  };
}
#endif
