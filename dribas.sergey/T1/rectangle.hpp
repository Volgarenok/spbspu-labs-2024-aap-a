#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace dribas
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(double leftDown, double rightUp);
    double getArea() const  override;
    Rectange_t getFrameRect() const override;
    void move(Point_t point) override;
    void move(double x, double y) override;
    void scale(double ratio) override;
  private:
    double LeftDown_;
    double rightUp_;
  };
}
#endif