#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "regular.hpp"

namespace rychkov
{
  class Rectangle final: public Shape
  {
  public:
    Rectangle() = delete;
    Rectangle(point_t bottomLeft, point_t topRight);

    virtual double getArea() const noexcept override;
    virtual rectangle_t getFrameRect() const noexcept override;
    virtual void move(point_t destination) noexcept override;
    virtual void move(double deltaX, double deltaY) noexcept override;
    virtual Shape* clone() const override;
  private:
    static constexpr double maxError = 0.0001;
    Regular bottomLeft_;
    long localHeight_, localWidth_;
    virtual void unsafeScale(double coef) noexcept override;
    double tryLocalRotation(double height, double width, double bestSideLength);
    static Regular generateBasisHexagon(point_t bottomLeft, double sideLength, bool isHorizontal);
    static double getSideLength(long localHeight, long localWidth, double height, double width);
  };
}

#endif
