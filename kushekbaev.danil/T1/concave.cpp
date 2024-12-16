#include "concave.hpp"
#include "base-types.hpp"
#include <cmath>
#include <stdexcept>

namespace kushekbaev
{
  Concave::Concave(point_t first, point_t second, point_t third, point_t final)
  : first_(first), second_(second), third_(third), final_(final) {}

  double Concave::getArea() const
  {
    double halfperimeterOfTriangle = (getLineLength(first_, second_) + getLineLength(second_, third_)
    + getLineLength(first_, third_)) / 2;
    double squaredAreaOfTriangle = (halfperimeterOfTriangle)
    * (halfperimeterOfTriangle - getLineLength(first_, second_))
    * (halfperimeterOfTriangle - getLineLength(second_, third_))
    * (halfperimeterOfTriangle - getLineLength(first_, third_));
    double areaOfTriangle = std::sqrt(squaredAreaOfTriangle);

    double halfperimeterOfConcavity = (getLineLength(second_, third_) + getLineLength(third_, final_)
    + getLineLength(second_, final_));
    double squaredAreaOfConcavity = (halfperimeterOfConcavity)
    * (halfperimeterOfConcavity - getLineLength(second_, third_))
    * (halfperimeterOfConcavity - getLineLength(third_, final_))
    * (halfperimeterOfConcavity - getLineLength(second_, final_));
    double areaOfConcavity = std::sqrt(squaredAreaOfConcavity);

    return areaOfTriangle - areaOfConcavity;
  }

  rectangle_t Concave::getFrameRect() const
  {
    point_t lowerLeft { 0, 0 };
    double lowerLeftX = 0;
    (first_.x > second_.x) ? ((first_.x > third_.x) ? lowerLeftX = first_.x : lowerLeftX = third_.x)
    : ((second_.x > third_.x) ? lowerLeftX = second_.x : lowerLeftX = third_.x);
    lowerLeft.x = lowerLeftX;

    double lowerLeftY = 0;
    (first_.y > second_.y) ? ((first_.y > third_.y) ? lowerLeftY = first_.y : lowerLeftY = third_.y)
    : ((second_.y > third_.y) ? lowerLeftY = second_.y : lowerLeftY = third_.y);
    lowerLeft.y = lowerLeftY;

    point_t upperRight { 0, 0 };
    double upperRightX = 0;
    (first_.x > second_.x) ? ((first_.x > third_.x) ? upperRightX = first_.x : upperRightX = third_.x)
    : ((second_.x > third_.x) ? upperRightX = second_.x : upperRightX = third_.x);
    upperRight.x = upperRightX;

    double upperRightY = 0;
    (first_.y > second_.y) ? ((first_.y > third_.y) ? upperRightY = first_.y : upperRightY = third_.y)
    : ((second_.y > third_.y) ? upperRightY = second_.y : upperRightY = third_.y);
    upperRight.y = upperRightY;

    double middleForX = lowerLeft.x + (upperRight.x - lowerLeft.x) / 2;
    double middleForY = lowerLeft.y + (upperRight.y - lowerLeft.y) / 2;

    rectangle_t* rect = new rectangle_t
    { upperRight.x - lowerLeft.x, upperRight.y - lowerLeft.y, { middleForX, middleForY } };
    return *rect;
  }

  void Concave::move(point_t Z)
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
    final_.x += moveX;
    final_.y += moveY;
  }

  void Concave::move(double dx, double dy)
  {
    first_.x += dx;
    first_.y += dy;
    second_.x += dx;
    second_.y += dy;
    third_.x += dx;
    third_.y += dy;
    final_.x += dx;
    final_.y += dy;
  }

  void Concave::scale(double V)
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
    final_.x = middle.x + (final_.x - middle.x) * V;
    final_.y = middle.y + (final_.y - middle.y) * V;
  }
}
