#ifndef DIAMOND_H
#define DIAMOND_H
#include "shape.h"

namespace cherkasov
{
  class Diamond : public Shape
  {
  public:
    Diamond(point_t d1, point_t d2, point_t d3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t c) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t center;
    double width;
    double height;
  };
}
#endif
