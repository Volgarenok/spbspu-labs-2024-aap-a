#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <cstddef>

#include "shape.hpp"
#include "rectangle.hpp"

namespace guseynov
{
  class Square : public Shape
  {
  public:
    Square(point_t leftLowP, double length);
    ~Square() override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double x, double y) override;
    void scaleWithoutCheck(double k) override;
    Shape * clone() const override;
  private:
    size_t n_;
    guseynov::Rectangle ** rectangleArray_;
    void assigment(point_t leftLowP);
    Rectangle ** createArrayRectangle(point_t lower, double squareLength);
    void assigmentPlusLength(point_t leftLowP, double length);
    size_t determinateNum(double squareLength);
    void clear(size_t count);
  };
}

#endif
