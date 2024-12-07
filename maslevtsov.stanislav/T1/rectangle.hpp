#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace maslevtsov
{
  struct Rectangle: public Shape
  {
  public:
    Rectangle(point_t bottomLeft, point_t topRight);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pnt) override;
    void move(double dx, double dy) override;
    void scale(double k) override;

  private:
    point_t bottomLeft_;
    point_t topRight_;
  };

  Rectangle* makeRectangle(const double* arguments);
  Rectangle* makeRectangle(std::istream& in);
}

#endif
