#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>
#include <cctype>
#include <array>
#include "shape.hpp"
#include "shapeBreeding.hpp"

namespace
{
  bool parallelX(kushekbaev::point_t first, kushekbaev::point_t second)
  {
    return (first.x == second.x);
  }
}

namespace kushekbaev
{
  Parallelogram::Parallelogram(point_t first, point_t second, point_t third):
    first_(first),
    second_(second),
    third_(third)
  {
    bool isParallelToX = parallelX(first, second) || parallelX (second, third) || parallelX(first, third);
    if (!isTriangle(first, second, third) || !isParallelToX)
    {
      throw std::invalid_argument("Incorrect parallelogram\n");
    }
  }

  double Parallelogram::getArea() const
  {
    double firstSecondLL = getLineLength(first_, second_);
    double secondThirdLL = getLineLength(second_, third_);
    double firstThirdLL = getLineLength(first_, third_);
    double p = (firstSecondLL + secondThirdLL + firstThirdLL) / 2;
    double squaredAreaOfTriangle = (p) * (p - firstSecondLL) * (p - secondThirdLL) * (p - firstThirdLL);
    double areaOfTriangle = std::sqrt(squaredAreaOfTriangle);
    return 2 * areaOfTriangle;
  }

  rectangle_t Parallelogram::getFrameRect() const
  {
    point_t firstalt({ first_.x + third_.x - second_.x, first_.y + third_.y - second_.y });

    double heigth = std::abs(first_.y - third_.y);
    double maxX = std::max(std::max(first_.x, second_.x), std::max(third_.x, firstalt.x));
    double minX = std::min(std::min(first_.x, second_.x), std::min(third_.x, firstalt.x));
    double width = maxX - minX;
    double middleX = (first_.x + second_.x + third_.x + firstalt.x) / 4.0;
    double middleY = (first_.y + second_.y + third_.y + firstalt.y) / 4.0;
    return { width, heigth, { middleX, middleY } };
  }

  void Parallelogram::move(point_t scalePoint)
  {
    point_t middle = getFrameRect().pos;
    double dX = scalePoint.x - middle.x;
    double dY = scalePoint.y - middle.y;

    move(dX, dY);
  }

  void Parallelogram::move(double dx, double dy)
  {
    std::array<point_t*, 3> points = { &first_, &second_, &third_};

    for (point_t* point: points)
    {
      point->x += dx;
      point->y += dy;
    }
  }

  void Parallelogram::scale(double scaleCoeff)
  {
    if (scaleCoeff <= 0)
    {
      throw std::out_of_range("Scale coefficient should be greater than zero\n");
    }
    point_t middle = getFrameRect().pos;

    std::array<point_t*, 3> points = { &first_, &second_, &third_ };

    for (point_t* point: points)
    {
      point->x = middle.x + (point->x - middle.x) * scaleCoeff;
      point->y = middle.y + (point->y - middle.y) * scaleCoeff;
    }
  }
}
