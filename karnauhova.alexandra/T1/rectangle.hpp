#include "shape.hpp"
class Rectangle: public Shape
{
public:
  Rectangle(point_t x4, point_t x2): x4_(x4), x2_(x2)
  {
    x1_.x = x4_.x;
    x1_.y = x2_.y;
    x3_.x = x2_.x;
    x3_.y = x4_.y;
    
    getFrameRect();
  }
  void move(double x, double y);
  void move(point_t t);
  double getArea();
  void getFrameRect();
  ~Rectangle(){}
private:
  point_t x1_;
  point_t x2_;
  point_t x3_;
  point_t x4_;
  point_t centr;
};
