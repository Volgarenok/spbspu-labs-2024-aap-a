#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"
namespace asafov
{
  class Square final : public Shape
  {
    
  public:
    Square(point_t a, double side);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double scale);
  private:
    point_t lb_;
    double side_;
  };
}
#endif
