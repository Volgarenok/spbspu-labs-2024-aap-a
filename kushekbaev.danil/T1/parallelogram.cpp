#include "shape.hpp"
#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>
#include <cctype>

namespace kushekbaev
{
  Parallelogram::Parallelogram(point_t first, point_t second, point_t third)
  : first_(first), second_(second), third_(third){}

  double Parallelogram::getArea() const
  {
    double halfperimeterOfTriangle = (getLineLength(first_, second_) + getLineLength(second_, third_)
    + getLineLength(first_, third_)) / 2;
    double squaredAreaOfTriangle = (halfperimeterOfTriangle)
    * (halfperimeterOfTriangle - getLineLength(first_, second_))
    * (halfperimeterOfTriangle - getLineLength(second_, third_))
    * (halfperimeterOfTriangle - getLineLength(first_, third_));
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

    point_t middle = this->getFrameRect().pos;
    double moveX = Z.x - middle.x;
    double moveY = Z.y - middle.y;
    first_.x += moveX;
    first_.y += moveY;
    second_.x += moveX;
    second_.y += moveY;
    third_.x += moveX;
    third_.y += moveY;
    firstalt.x += moveX;
    firstalt.y += moveY;
  }

  void Parallelogram::move(double dx, double dy)
  {
    point_t firstalt({ first_.x + third_.x - second_.x, first_.y + third_.y - second_.y });

    first_.x += dx;
    first_.y += dy;
    second_.x += dx;
    second_.y += dy;
    third_.x += dx;
    third_.y += dy;
    firstalt.x += dx;
    firstalt.y += dy;
  }

  void Parallelogram::scale(double V)
  {
    point_t firstalt({ first_.x + third_.x - second_.x, first_.y + third_.y - second_.y });
    if (V <= 0)
    {
      throw std::invalid_argument("Scale coefficient should be greater than zero\n");
    }
    point_t middle = this->getFrameRect().pos;
    first_.x = middle.x + (first_.x - middle.x) * V;
    first_.y = middle.y + (first_.y - middle.y) * V;
    second_.x = middle.x + (second_.x - middle.x) * V;
    second_.y = middle.y + (second_.y - middle.y) * V;
    third_.x = middle.x + (third_.x - middle.x) * V;
    third_.y = middle.y + (third_.y - middle.y) * V;
    firstalt.x = middle.x + (firstalt.x - middle.x) * V;
    firstalt.y = middle.y + (firstalt.y - middle.y) * V;
  }
}
