#ifndef RECTANGE_HPP
#define RECTANGE_HPP
#include "triangle.hpp"
namespace nikonov
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(const point_t &lbp, const point_t &rtp);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &a) override;
    void move(double x, double y) override;
    void scale(double k) noexcept override;
    Shape *clone() const override;
  private:
    Triangle left_;
    Triangle right_;
    Triangle top_;
    Triangle bot_;
  };
}
#endif
