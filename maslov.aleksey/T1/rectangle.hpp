#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include <utility>
#include "regular.hpp"

namespace maslov
{
  struct Rectangle final: public Shape
  {
    Rectangle(point_t lowerLeftCorner, point_t upperRightCorner);
    ~Rectangle() override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t s) override;
    void move(double dx, double dy) override;
    void scaleWithoutCheck(double k) override;
    Shape * clone() const override;
   private:
    size_t n_;
    size_t nWidth_;
    Regular ** regularArray_;
    void clear(size_t count);
    double calculateSide(point_t lower, point_t upper);
    size_t calculateSquares(point_t lower, point_t upper);
    std::pair<size_t, size_t> calculateSquaresOnSides(point_t lower, point_t upper);
    Regular ** createRegularArray(point_t lower, point_t upper);
  };
}

#endif
