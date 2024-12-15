#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace dribas
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(Point_t leftDown, Point_t rightUp);
    double getArea() const  override;
    Rectangle_t getFrameRect() const override;
    void move(Point_t point) override;
    void move(double x, double y) override;
    void scale(double ratio) override;
  private:
    Point_t leftDown_;
    Point_t rightUp_;
  };
}
#endif
