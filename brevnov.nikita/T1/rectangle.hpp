#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "ellipse.hpp"
namespace brevnov
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle(point_t left, point_t right);
    ~Rectangle();
    double getArea() const noexcept override;
    rectangle_t getFrameRect() const noexcept override;
    void move(point_t new_centre) noexcept override;
    void move(double dx, double dy) noexcept override;
    void scale(double n) noexcept override;
    Shape * clone() const;
  private:
    Shape ** shapes_;
    point_t left_;
    point_t right_;
  };
}
#endif
