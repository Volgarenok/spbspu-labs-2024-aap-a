#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
#include "base-types.h"
namespace cherkasov
{
  class Square : public Shape
  {
  public:
    Square(point_t lowLeft, double leght);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t c) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    rectangle_t square;
  };
}
#endif
