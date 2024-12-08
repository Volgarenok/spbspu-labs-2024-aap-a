#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

namespace dribas
{
  class Triangle : public Shape
  {
  public:
    Triangle(Point_t a, Point_t b, Point_t c);
    double getArea() const  override;
    Rectangle_t getFrameRect() const override;
    void move(Point_t point) override;
    void move(double x, double y) override;
    void scale(double ratio) override;
  private:
    Point_t a_;
    Point_t b_;
    Point_t c_;
  };
}
#endif
