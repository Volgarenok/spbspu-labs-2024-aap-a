#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <cstddef>

#include "shape.hpp"
#include "rectangle.hpp"

namespace guseynov
{
  class Square final : public Shape
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
    point_t leftLowP_;
    size_t n_;
    double length_;
    guseynov::Rectangle ** rectangleArray_;
    void createArrayRectangle(point_t lower, double squareLength, size_t m, size_t n);
    void assigment(point_t leftLowP);
    void assigment(point_t leftLowP, double length);
    size_t determinateNum(double squareLength);
    void clear(size_t count);
  };
}

#endif
