#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
namespace cherkasov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t lowLeft, point_t upRight);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    rectangle_t rect;
  };
}
#endif
