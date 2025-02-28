#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"
namespace asafov
{
  class Square final: public Shape
  {
    virtual void unsafeScale(double scale) = 0;
  public:
    Square(point_t lb, double side);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double dx, double dy);
    void scale(double scale);
  private:
    point_t lb_;
    double side_;
  };
}
#endif
