#include "diamond.hpp"
#include "shape.hpp"
#include <cmath>
#include <stdexcept>

namespace kushekbaev
{
  Diamond::Diamond(point_t first, point_t second, point_t third)
  : first_(first), second_(second), third_(third){}

  double Diamond::getArea() const
  {
    double halfperimeterOfTriangle = (getLineLength(first_, second_) + getLineLength(second_, third_)
    + getLineLength(first_, third_)) / 2;
    double squaredAreaOfTriangle = (halfperimeterOfTriangle)
    * (halfperimeterOfTriangle - getLineLength(first_, second_))
    * (halfperimeterOfTriangle - getLineLength(second_, third_))
    * (halfperimeterOfTriangle - getLineLength(first_, third_));
    double areaOfTriangle = std::sqrt(squaredAreaOfTriangle);

    return 4 * areaOfTriangle;
  }

  rectangle_t Diamond::getFrameRect() const
  {
    double length = 0;
    double width = 0;

    double XparallelLine = 0;
    (first_.x == second_.x) ?
    ((first_.x == third_.x) ?
    XparallelLine = getLineLength(first_, third_) :
    (second_.x == third_.x) ?
    XparallelLine = getLineLength(second_, third_) :
    throw std::invalid_argument("There is no line parallel to X\n")) :
    (second_.x == third_.x) ?
    XparallelLine = getLineLength(second_, third_) :
    ((first_.x == third_.x) ?
    XparallelLine = getLineLength(first_, third_) :
    throw std::invalid_argument("There is no line parallel to X\n"));

    double YparallelLine = 0;
    (first_.y == second_.y) ?
    ((first_.y == third_.y) ?
    YparallelLine = getLineLength(first_, third_) :
    (second_.y == third_.y) ?
    YparallelLine = getLineLength(second_, third_) :
    throw std::invalid_argument("There is no line parallel to Y\n")) :
    (second_.y == third_.y) ?
    YparallelLine = getLineLength(second_, third_) :
    ((first_.y == third_.y) ?
    YparallelLine = getLineLength(first_, third_) :
    throw std::invalid_argument("There is no line parallel to Y\n"));

    point_t middle { XparallelLine, YparallelLine };
    if (middle.x == first_.x && middle.y == first_.y)
    {
      (second_.x > third_.x) ?
      width = second_.x : width = third_.x;

      (second_.y > third_.y) ?
      length = second_.y : length = third_.y;
    }

    else if (middle.x == second_.x && middle.y == second_.y)
    {
      (second_.x > third_.x) ?
      width = second_.x : width = third_.x;

      (second_.y > third_.y) ?
      length = second_.y : length = third_.y;
    }

    else if (middle.x == third_.x && middle.x == third_.y)
    {
      (second_.x > first_.x) ?
      width = second_.x : width = first_.x;

      (second_.y > first_.y) ?
      length = second_.y : length = first_.y;
    }

    return { width, length, middle };
  }

  void Diamond::move(point_t Z)
  {
    point_t middle = this->getFrameRect().pos;
    double moveX = Z.x - middle.x;
    double moveY = Z.y - middle.y;
    first_.x += moveX;
    first_.y += moveY;
    second_.x += moveX;
    second_.y += moveY;
    third_.x += moveX;
    third_.y += moveY;
  }

  void Diamond::move(double dx, double dy)
  {
    first_.x += dx;
    first_.y += dy;
    second_.x += dx;
    second_.y += dy;
    third_.x += dx;
    third_.y += dy;
  }

  void Diamond::scale(double V)
  {
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
  }

}
