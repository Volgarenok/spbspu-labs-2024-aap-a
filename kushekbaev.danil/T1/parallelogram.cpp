#include "shape.hpp"
#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>

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
    point_t firstalt { 0, 0 };
    double height = getArea() / getLineLength(second_, third_);
    firstalt.x += 2 * height;
    firstalt.y += 2 * height;

    point_t lowerLeft { 0, 0 };
    double lowerLeftX = 0;
    lowerLeftX = (first_.x > second_.x) ?
                ((first_.x > third_.x) ?
                ((first_.x > firstalt.x) ? first_.x : firstalt.x) :
                ((third_.x > firstalt.x) ? third_.x : firstalt.x)) :
                ((second_.x > third_.x) ?
                ((second_.x > firstalt.x) ? second_.x : firstalt.x) :
                ((third_.x > firstalt.x) ? third_.x : firstalt.x));
    lowerLeft.x = lowerLeftX;

    double lowerLeftY = 0;
    lowerLeftY = (first_.y > second_.y) ?
                ((first_.y > third_.y) ?
                ((first_.y > firstalt.y) ? first_.y : firstalt.y) :
                ((third_.y > firstalt.y) ? third_.y : firstalt.y)) :
                ((second_.y > third_.y) ?
                ((second_.y > firstalt.y) ? second_.y : firstalt.y) :
                ((third_.y > firstalt.y) ? third_.y : firstalt.y));
    lowerLeft.y = lowerLeftY;

    point_t upperRight { 0, 0 };
    double upperRightX = 0;
    upperRightX = (first_.x > second_.x) ?
                ((first_.x > third_.x) ?
                ((first_.x > firstalt.x) ? first_.x : firstalt.x) :
                ((third_.x > firstalt.x) ? third_.x : firstalt.x)) :
                ((second_.x > third_.x) ?
                ((second_.x > firstalt.x) ? second_.x : firstalt.x) :
                ((third_.x > firstalt.x) ? third_.x : firstalt.x));
    upperRight.x = upperRightX;

    double upperRightY = 0;
    upperRightY = (first_.y > second_.y) ?
                ((first_.y > third_.y) ?
                ((first_.y > firstalt.y) ? first_.y : firstalt.y) :
                ((third_.y > firstalt.y) ? third_.y : firstalt.y)) :
                ((second_.y > third_.y) ?
                ((second_.y > firstalt.y) ? second_.y : firstalt.y) :
                ((third_.y > firstalt.y) ? third_.y : firstalt.y));
    upperRight.y = upperRightY;

    double middleForX = lowerLeft.x + (upperRight.x - lowerLeft.x) / 2;
    double middleForY = lowerLeft.y + (upperRight.y - lowerLeft.y) / 2;

    rectangle_t* rect = new rectangle_t{ upperRight.x - lowerLeft.x, upperRight.y - lowerLeft.y, { middleForX, middleForY } };
    return *rect;
  }

  void Parallelogram::move(point_t Z)
  {
    point_t firstalt { 0, 0 };
    double height = getArea() / getLineLength(second_, third_);
    firstalt.x += 2 * height;
    firstalt.y += 2 * height;

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
    point_t firstalt { 0, 0 };
    double height = getArea() / getLineLength(second_, third_);
    firstalt.x += 2 * height;
    firstalt.y += 2 * height;

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
    point_t firstalt { 0, 0 };
    double height = getArea() / getLineLength(second_, third_);
    firstalt.x += 2 * height;
    firstalt.y += 2 * height;

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
