#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>
#include <cctype>
#include "shape.hpp"

namespace kushekbaev
{
  Parallelogram::Parallelogram(point_t first,
    point_t second,
    point_t third):
    first_(first),
    second_(second),
    third_(third)
  {}

  double Parallelogram::getArea() const
  {
    double p = (getLineLength(first_, second_) + getLineLength(second_, third_)
    + getLineLength(first_, third_)) / 2;
    double squaredAreaOfTriangle = (p) * (p - getLineLength(first_, second_))
    * (p - getLineLength(second_, third_)) * (p - getLineLength(first_, third_));
    double areaOfTriangle = std::sqrt(squaredAreaOfTriangle);

    return 2 * areaOfTriangle;
  }

  rectangle_t Parallelogram::getFrameRect() const
  {
    point_t firstalt({ first_.x + third_.x - second_.x, first_.y + third_.y - second_.y });

    double heigth = std::abs(first_.y - third_.y);
    double maxX = std::max(std::max(first_.x, second_.x), std::max(third_.x,firstalt.x));
    double minX = std::min(std::min(first_.x, second_.x), std::min(third_.x,firstalt.x));
    double width = maxX - minX;
    double middleX = (first_.x + second_.x + third_.x + firstalt.x) / 4.0;
    double middleY = (first_.y + second_.y + third_.y + firstalt.y) / 4.0;
    return { width, heigth, { middleX, middleY } };
  }

  void Parallelogram::move(point_t Z)
  {
    point_t firstalt({ first_.x + third_.x - second_.x, first_.y + third_.y - second_.y });

    point_t middle = getFrameRect().pos;
    double dx = Z.x - middle.x;
    double dy = Z.y - middle.y;
    moveDelta(dx, dy, first_);
    moveDelta(dx, dy, second_);
    moveDelta(dx, dy, third_);
    moveDelta(dx, dy, firstalt);
  }

  void Parallelogram::move(double dx, double dy)
  {
    point_t firstalt({ first_.x + third_.x - second_.x, first_.y + third_.y - second_.y });

    moveDelta(dx, dy, first_);
    moveDelta(dx, dy, second_);
    moveDelta(dx, dy, third_);
    moveDelta(dx, dy, firstalt);
  }

  void Parallelogram::scale(double V)
  {
    point_t firstalt({ first_.x + third_.x - second_.x, first_.y + third_.y - second_.y });
    if (V <= 0)
    {
      throw std::out_of_range("Scale coefficient should be greater than zero\n");
    }
    point_t middle = getFrameRect().pos;
    isoScaling(V, middle, first_);
    isoScaling(V, middle, second_);
    isoScaling(V, middle, third_);
    isoScaling(V, middle, firstalt);
  }
}
